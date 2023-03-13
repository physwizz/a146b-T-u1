/* SPDX-License-Identifier: GPL-2.0 */
#ifndef SSG_H
#define SSG_H

#include <linux/blk-cgroup.h>

struct ssg_request_info {
	pid_t tgid;
	char tg_name[TASK_COMM_LEN];
	u64 tg_start_time;

	struct blkcg_gq *blkg;

	unsigned int data_size;
};

struct ssg_data {
	struct request_queue *queue;

	/*
	 * requests are present on both sort_list and fifo_list
	 */
	struct rb_root sort_list[2];
	struct list_head fifo_list[2];

	/*
	 * next in sort order. read, write or both are NULL
	 */
	struct request *next_rq[2];
	unsigned int starved_writes;	/* times reads have starved writes */

	/*
	 * settings that change how the i/o scheduler behaves
	 */
	int fifo_expire[2];
	int max_write_starvation;
	int front_merges;

	/*
	 * to control request allocation
	 */
	atomic_t allocated_rqs;
	atomic_t async_write_rqs;
	int congestion_threshold_rqs;
	int max_tgroup_rqs;
	int max_async_write_rqs;
	unsigned int tgroup_shallow_depth;	/* thread group shallow depth for each tag map */
	unsigned int async_write_shallow_depth;	/* async write shallow depth for each tag map */

	/*
	 * I/O context information for each request
	 */
	struct ssg_request_info *rq_info;

	/*
	 * Statistics
	 */
	void __percpu *stats;

	spinlock_t lock;
	spinlock_t zone_lock;
	struct list_head dispatch;
};

/* ssg-stat.c */
extern int ssg_stat_init(struct ssg_data *ssg);
extern void ssg_stat_exit(struct ssg_data *ssg);
extern void ssg_stat_account_io_done(struct ssg_data *ssg,
		struct request *rq, unsigned int data_size, u64 now);
extern ssize_t ssg_stat_read_latency_show(struct elevator_queue *e, char *page);
extern ssize_t ssg_stat_write_latency_show(struct elevator_queue *e, char *page);
extern ssize_t ssg_stat_flush_latency_show(struct elevator_queue *e, char *page);
extern ssize_t ssg_stat_discard_latency_show(struct elevator_queue *e, char *page);
extern ssize_t ssg_stat_inflight_show(struct elevator_queue *e, char *page);

/* ssg-cgroup.c */
#if IS_ENABLED(CONFIG_MQ_IOSCHED_SSG_CGROUP)
struct ssg_blkcg {
	struct blkcg_policy_data cpd; /* must be the first member */

	int max_available_ratio;
};

struct ssg_blkg {
	struct blkg_policy_data pd; /* must be the first member */

	atomic_t current_rqs;
	int max_available_rqs;
	unsigned int shallow_depth; /* shallow depth for each tag map to get sched tag */
};

extern int ssg_blkcg_init(void);
extern void ssg_blkcg_exit(void);
extern int ssg_blkcg_activate(struct request_queue *q);
extern void ssg_blkcg_deactivate(struct request_queue *q);
extern unsigned int ssg_blkcg_shallow_depth(struct request_queue *q);
extern void ssg_blkcg_depth_updated(struct blk_mq_hw_ctx *hctx);
extern void ssg_blkcg_inc_rq(struct blkcg_gq *blkg);
extern void ssg_blkcg_dec_rq(struct blkcg_gq *blkg);
#else
static inline int ssg_blkcg_init(void)
{
	return 0;
}
static inline void ssg_blkcg_exit(void)
{
}

static inline int ssg_blkcg_activate(struct request_queue *q)
{
	return 0;
}

static inline void ssg_blkcg_deactivate(struct request_queue *q)
{
}

static inline unsigned int ssg_blkcg_shallow_depth(struct request_queue *q)
{
	return 0;
}

static inline void ssg_blkcg_depth_updated(struct blk_mq_hw_ctx *hctx)
{
}

static inline void ssg_blkcg_inc_rq(struct blkcg_gq *blkg)
{
}

static inline void ssg_blkcg_dec_rq(struct blkcg_gq *blkg)
{
}
#endif

/* blk-sec-stat.c */
#if IS_ENABLED(CONFIG_BLK_SEC_STATS)
extern void blk_sec_stat_account_init(struct request_queue *q);
extern void blk_sec_stat_account_exit(struct elevator_queue *eq);
extern void blk_sec_stat_account_io_done(
		struct request *rq, unsigned int data_size,
		pid_t tgid, const char *tg_name, u64 tg_start_time);
#else
static inline void blk_sec_stat_account_init(struct request_queue *q)
{
}

static inline void blk_sec_stat_account_exit(struct elevator_queue *eq)
{
}

static inline void blk_sec_stat_account_io_done(
		struct request *rq, unsigned int data_size,
		pid_t tgid, const char *tg_name, u64 tg_start_time)
{
}
#endif

#endif // SSG_H
