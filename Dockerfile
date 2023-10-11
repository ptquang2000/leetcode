# syntax=docker/dockerfile:1

FROM archlinux:latest
ENV TERM xterm-256color
RUN pacman -Sy --noconfirm git unzip clang make cmake tmux neovim
RUN git clone https://github.com/ptquang2000/kickstart.nvim.git "${XDG_CONFIG_HOME:-$HOME/.config}"/nvim
RUN echo 'set -g default-terminal "screen-256color"' >> ~/.tmux.conf
WORKDIR /leetcode
