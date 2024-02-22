#!/usr/bin/env bash

set -eou pipefail

#ref https://docs.flathub.org/docs/for-app-authors/submission/

flatpak-builder --force-clean --sandbox --user --install \
    --ccache --mirror-screenshots-url=https://dl.flathub.org/media/ \
    --repo=repo builddir \
    io.github.ttys3.webview.yml


