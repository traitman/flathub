#!/usr/bin/env bash

set -eou pipefail

flatpak run org.flatpak.Builder --force-clean --disable-cache --sandbox --user --install --ccache --repo=repo builddir io.github.ttys3.webview.yml
