# syntax=docker/dockerfile:1

FROM archlinux:latest
RUN pacman -Sy --noconfirm git unzip clang make cmake tmux neovim
RUN git clone https://github.com/ptquang2000/kickstart.nvim.git "${XDG_CONFIG_HOME:-$HOME/.config}"/nvim
WORKDIR /leetcode