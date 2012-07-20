/*
 * QEMU buffered QEMUFile
 *
 * Copyright IBM, Corp. 2008
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
 */

#ifndef QEMU_BUFFERED_FILE_H
#define QEMU_BUFFERED_FILE_H

#include "hw/hw.h"
#include "migration.h"

typedef void (BufferedWaitForUnfreezeFunc)(void *opaque);
typedef int (BufferedCloseFunc)(void *opaque);

QEMUFile *qemu_fopen_ops_buffered(MigrationState *migration_state,
                                  size_t xfer_limit,
                                  BufferedWaitForUnfreezeFunc *wait_for_unfreeze,
                                  BufferedCloseFunc *close);

#endif
