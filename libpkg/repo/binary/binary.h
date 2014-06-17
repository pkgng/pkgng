/* Copyright (c) 2014, Vsevolod Stakhov
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *       * Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 *       * Redistributions in binary form must reproduce the above copyright
 *         notice, this list of conditions and the following disclaimer in the
 *         documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef BINARY_H_
#define BINARY_H_

#include "pkg.h"
#include "private/pkg.h"

#define PRIV_GET(repo) (sqlite3 *)(repo)->priv;

extern struct pkg_repo_ops pkg_repo_binary_ops;

int pkg_repo_binary_update(struct pkg_repo *repo, bool force);
int pkg_repo_binary_init(struct pkg_repo *repo);
int pkg_repo_binary_close(struct pkg_repo *repo, bool commit);
int pkg_repo_binary_access(struct pkg_repo *repo, unsigned mode);

int pkg_repo_binary_create(struct pkg_repo *repo);
int pkg_repo_binary_open(struct pkg_repo *repo, unsigned mode);

struct pkg_repo_it *pkg_repo_binary_query(struct pkg_repo *repo,
	const char *pattern, match_t match);
struct pkg_repo_it *pkg_repo_binary_shlib_provide(struct pkg_repo *repo,
	const char *require);
struct pkg_repo_it *pkg_repo_binary_shlib_require(struct pkg_repo *repo,
	const char *provide);
struct pkg_repo_it *pkg_repo_binary_search(struct pkg_repo *repo,
	const char *pattern, match_t match,
    pkgdb_field field, pkgdb_field sort);

#endif /* BINARY_H_ */
