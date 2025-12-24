{
  description = "dev shells!";

  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-25.11";

  outputs = inputs @ {self, ...}: let
    systems = [
      "x86_64-darwin"
      "x86_64-linux"
      "aarch64-darwin"
      "aarch64-linux"
    ];

    forAllSystems = inputs.nixpkgs.lib.genAttrs systems;
    nixpkgsFor = forAllSystems (system: inputs.nixpkgs.legacyPackages.${system});
  in {
    devShells = forAllSystems (system: let
      pkgs = nixpkgsFor.${system};
    in {
      default = pkgs.mkShell {
        buildInputs = [
          # x
          pkgs.just

          # c/c++
          pkgs.clang-tools
          pkgs.clang
          pkgs.libclang
          pkgs.libcxx

          # python
          pkgs.ruff
          pkgs.ty
          pkgs.uv

          # rust
          pkgs.bacon
          pkgs.cargo
          pkgs.cargo-bump
          pkgs.clippy
          pkgs.rustc
          pkgs.rustfmt
        ];
      };

      cpp = pkgs.mkShell {
        buildInputs = [
          pkgs.clang-tools
          pkgs.clang
          pkgs.just
          pkgs.libclang
          pkgs.libcxx
        ];
      };

      py = pkgs.mkShell {
        buildInputs = [
          pkgs.just
          pkgs.ruff
          pkgs.ty
          pkgs.uv
        ];
      };

      rs = pkgs.mkShell {
        buildInputs = [
          pkgs.bacon
          pkgs.cargo
          pkgs.cargo-bump
          pkgs.clippy
          pkgs.just
          pkgs.rustc
          pkgs.rustfmt
        ];
      };
    });
  };
}
