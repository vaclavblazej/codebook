#!/usr/bin/env sh

cd "$(dirname "$0")"/../../make/ || exit \
    && cargo clippy --all-targets --all-features --release --target-dir /tmp/codebook \
    && echo "clippy okay" \
    && cargo build --all-targets --release --target-dir /tmp/codebook \
    && echo "compiled okay" \
    || exit

/tmp/codebook/release/codebook "$@" &

cd ../web || exit \
    && hugo server -D
