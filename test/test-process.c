/*****************************************************************************
 *   Copyright 2014 - 2014 Yichao Yu <yyc1992@gmail.com>                     *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU Lesser General Public License as          *
 *   published by the Free Software Foundation; either version 2.1 of the    *
 *   License, or (at your option) version 3, or any later version accepted   *
 *   by the membership of KDE e.V. (or its successor approved by the         *
 *   membership of KDE e.V.), which shall act as a proxy defined in          *
 *   Section 6 of version 3 of the license.                                  *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU       *
 *   Lesser General Public License for more details.                         *
 *                                                                           *
 *   You should have received a copy of the GNU Lesser General Public        *
 *   License along with this library. If not,                                *
 *   see <http://www.gnu.org/licenses/>.                                     *
 *****************************************************************************/

#include <qtcurve-utils/process.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>

int pipe_fds[2];
long num;

static void
forkCb(void *data)
{
    QTC_UNUSED(data);
    write(pipe_fds[1], &num, sizeof(num));
}

int
main()
{
    int res = pipe(pipe_fds);
    assert(res == 0);
    srandom(time(NULL));
    num = random();
    bool fork_res = qtcForkBackground(forkCb, NULL);
    assert(fork_res);
    alarm(1);
    long num_sent = 0;
    ssize_t read_res = read(pipe_fds[0], &num_sent, sizeof(num_sent));
    assert(read_res == sizeof(num_sent));
    assert(num_sent = num);
    return 0;
}
