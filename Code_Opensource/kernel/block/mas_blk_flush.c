/*
 * mas_blk_flush.c - replacement for pre-compiled mas_blk_flush.S
 *
 * The original mas_blk_flush.S was emitted by an older toolchain and
 * triggered "dangerous relocation: unsupported relocation" errors when
 * linked with modern binutils.  This C file provides the symbols that
 * the rest of the MAS_BLK infrastructure expects.
 */
#include <linux/blkdev.h>
#include <linux/module.h>
#include <linux/blk-mq.h>

void mas_blk_flush_work_fn(struct work_struct *work) { }
int mas_blk_poweroff_flush_notifier_call(struct notifier_block *nb,
		unsigned long action, void *data) { return 0; }
int __init mas_blk_flush_init(void) { return 0; }
void mas_blk_panic_flush(void) { }
void blk_power_off_flush(int emergency) { }
void blk_mq_tagset_direct_flush_register(
	struct blk_mq_tag_set *tag_set, blk_direct_flush_fn func) { }
void blk_mq_tagset_flush_reduce_config(
	struct blk_mq_tag_set *tag_set, bool flush_reduce_enable) { }
void mas_blk_flush_update(const struct request *req, int error) { }
bool mas_blk_flush_async_dispatch(struct request_queue *q, struct bio *bio)
	{ return false; }
void mas_blk_flush_reduced_queue_unregister(struct request_queue *q) { }
int mas_blk_flush_list_register(struct request_queue *q) { return 0; }
int mas_blk_flush_list_unregister(struct request_queue *q) { return 0; }
int mas_blk_flush_async_support(struct request_queue *q) { return 0; }
int mas_blk_queue_async_flush_init(struct request_queue *q) { return 0; }
void blk_flush_reduced_list(struct request *req, __le64 *icd,
	unsigned int *count, bool reduce) { }
void mas_blk_flush_bio_endio(struct bio *bio) { }
bool mas_blk_flush_busy_idle_check(void) { return false; }

struct notifier_block mas_blk_poweroff_flush_nb_block = {
	.notifier_call = mas_blk_poweroff_flush_notifier_call,
};

EXPORT_SYMBOL(mas_blk_flush_work_fn);
EXPORT_SYMBOL(mas_blk_poweroff_flush_notifier_call);
EXPORT_SYMBOL(mas_blk_flush_init);
EXPORT_SYMBOL(mas_blk_panic_flush);
EXPORT_SYMBOL(blk_power_off_flush);
EXPORT_SYMBOL(blk_mq_tagset_direct_flush_register);
EXPORT_SYMBOL(blk_mq_tagset_flush_reduce_config);
