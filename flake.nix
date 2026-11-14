{
  description = "Competitive Programming Environment (Modern C++)";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
  let
    system = "aarch64-darwin"; # change to x86_64-darwin if Intel Mac
    pkgs = import nixpkgs { inherit system; };
  in {
    devShells.${system}.default = pkgs.mkShell {
      packages = with pkgs; [
        # Latest compilers
        gcc14
        clang

        # Build tools
        cmake
        ninja
        gnumake

        # Debugging
        lldb

        # Utilities
        python3
        git
      ];

      shellHook = ''
        echo "⚡ Modern C++ CP Environment Loaded"
        echo "GCC: $(gcc --version | head -n 1)"
        echo "Clang: $(clang --version | head -n 1)"
      '';
    };
  };
}