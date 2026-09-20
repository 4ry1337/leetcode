{
  pkgs,
  lib,
  config,
  inputs,
  ...
}:
{
  languages.cplusplus.enable = true;

  # https://devenv.sh/packages/
  packages = with pkgs; [
    valgrind
    pkg-config
    clang
    clang-tools
  ];

  git-hooks.hooks = {
    typos.enable = true;
    clang-format.enable = true;
  };
}
