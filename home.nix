 #~/.config/home-manager/home.nix
{ config, pkgs, ... }:

{
  home.username = "nixos";
  home.homeDirectory = "/home/nixos";
  home.stateVersion = "24.05";


  programs.fish = {
    enable = true;
    shellInit = ''
      set -x WAYLAND_DISPLAY wayland-0
      set -x XDG_RUNTIME_DIR /mnt/wslg/runtime-dir

        if test -e /mnt/wslg/runtime-dir/wayland-0 -a ! -e /run/user/1000/wayland-0
          ln -s /mnt/wslg/runtime-dir/wayland-0 /run/user/1000/wayland-0
        end
        if test -d /run/user/1000
          # Ensure the directory is owned by the user "nixos"
          chown nixos:nixos /run/user/1000 2>/dev/null; or true
          chmod 0700 /run/user/1000
      end
        eval (fzf init fish)
        eval (zoxide init --cmd cd fish)

    '';
    shellAliases = {
      efish = "nvim ~/.config/fish/config.fish";
      sfish = "source ~/.config/fish/config.fish";
      rm = "trash";
      pc = "sudo pacman";
      zj = "zellij";
      gs = "git status";
      ga = "git add -A";
      gcom = "git commit -m";
      ehome = "nvim ~/.config/home-manager/home.nix";
      build_switch = "home-manager build && home-manager switch";
    };
    functions.lazyg = {
      body = ''
        git add -A && git commit -m $argv && git push
      '';
    };
    plugins = [
      # { name = "fzf-fish"; src = pkgs.fishPlugins.fzf-fish.src; }
      # { name = "grc"; src = pkgs.fishPlugins.grc.src; }
      # { name = "tide"; src = pkgs.fetchFromGitHub {
      #   owner = "IlanCosman";
      #   repo = "tide";
      #   rev = "v5.0.1";
      #   sha256 = "0dbnir6jbwjpjalz14snzd3cgdysgcs3raznsijd6savad3qhijc";
      # }; }
    ];
  };

  programs.home-manager.enable = true;

  programs.vscode = {
    enable = true;
    profiles.default.extensions = with pkgs.vscode-extensions; [
      bbenoist.nix
      ms-python.python
    ];
  };

  home.packages = with pkgs; [
    bat
    bun
    clang
    deno
    fd
    fzf
    gh
    git
    micro
    neovim
    nodejs
    openjdk23
    python312
    ripgrep
    rustup
    trash-cli
    weston
    wl-clipboard
    wget
    zellij
    zoxide
  ];

  nixpkgs.config.allowUnfreePredicate = _: true;
}
