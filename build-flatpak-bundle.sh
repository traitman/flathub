#!/usr/bin/env bash

set -eou pipefail


flatpak build-bundle --runtime ./repo \
    io.github.ttys3.webview.flatpak io.github.ttys3.webview \
    --runtime-repo=https://flathub.org/repo/flathub.flatpakrepo

