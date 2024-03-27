#!/usr/bin/env bash

set -eou pipefail

#ref https://docs.flathub.org/docs/for-app-authors/submission/
# tools prepare:
# flatpak install -y flathub org.flatpak.Builder
# or
# sudo dnf install -y flatpak-builder

flatpak run org.flatpak.Builder --sandbox --user --install \
    --ccache --mirror-screenshots-url=https://dl.flathub.org/media/ \
    --repo=repo builddir \
    io.github.ttys3.webview.yml


