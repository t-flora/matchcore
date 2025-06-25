# MatchCore

A high-performance matching engine built with C++ and Liquibook.

## Project Structure

```
matchcore/
├── external/              # External dependencies (submodules)
│   ├── liquibook/         # Liquibook order book implementation
│   └── MPC/               # Make Project Creator
├── scripts/               # Build and test scripts
├── src/                   # Source code
├── vcpkg/                 # Package manager for C++ dependencies
└── TEST_SETUP.md          # Detailed Liquibook setup and testing guide
```

## Quick Start

### Prerequisites

- **macOS** (tested on macOS 14.5.0)
- **Git** with submodule support
- **C++ compiler** (clang/gcc)
- **Make** and **Perl** (for MPC build system)

### Initial Setup

1. **Clone the repository with submodules:**
   ```bash
   git clone --recursive https://github.com/t-flora/matchcore.git
   cd matchcore
   ```

2. **If you already cloned without submodules:**
   ```bash
   git submodule update --init --recursive
   ```

3. **Install Boost via vcpkg:**
   ```bash
   ./vcpkg/vcpkg install boost
   ```

### Building and Testing Liquibook

1. **Set up the environment:**
   ```bash
   cd external/liquibook
   source ./env.sh
   ```

2. **Generate build files:**
   ```bash
   $MPC_ROOT/mwc.pl -type make liquibook.mwc
   ```

3. **Build and test:**
   ```bash
   make depend && make all
   bin/test/liquibook_unit_test
   ```

### Running Examples

```bash
# Manual order entry example
echo "help" | bin/mt_order_entry

# Performance test
bin/test/lt_order_book

# Interactive testing (Ctrl+C to exit)
bin/mt_order_entry
```

## Development Workflow

### Working with Submodules

This project uses custom forks of external dependencies with build fixes:

- **Liquibook**: Custom fork with vcpkg Boost integration
- **MPC**: Custom fork with vcpkg include path fixes
- **vcpkg**: Standard Microsoft package manager

### Adding New Dependencies

1. **Install via vcpkg:**
   ```bash
   ./vcpkg/vcpkg install <package-name>
   ```

2. **Update environment scripts** if needed
3. **Test integration** with existing build system

### Building Your Own Code

The project is set up for native development. Add your source files to `src/` and update `CMakeLists.txt` as needed.

## Performance

Liquibook achieves **2.0-2.5 million inserts per second** on modern hardware. The current setup includes:

- ✅ **157 unit tests** (12 known stop order failures)
- ✅ **Performance tests** (latency and throughput)
- ✅ **Manual order entry** example
- ✅ **vcpkg Boost integration** for reliable dependency management

## Troubleshooting

### Common Issues

1. **Submodule issues:**
   ```bash
   git submodule update --init --recursive
   ```

2. **Boost not found:**
   ```bash
   ./vcpkg/vcpkg install boost-test
   ```

3. **Build failures:**
   - Ensure you're in the liquibook directory
   - Source the environment: `source ./env.sh`
   - Regenerate Makefiles: `$MPC_ROOT/mwc.pl -type make liquibook.mwc`

### Debugging

1. **Check environment:**
   ```bash
   cd external/liquibook
   source ./env.sh
   echo $BOOST_ROOT
   echo $MPC_ROOT
   ```

2. **Run tests individually:**
   ```bash
   bin/test/liquibook_unit_test --run_test=test_name
   ```

## Architecture Notes

### Dependency Management

- **vcpkg**: C++ package manager for Boost and other dependencies
- **Submodules**: Git submodules for external repositories
- **MPC**: Make Project Creator for Liquibook build system

### Build System

- **MPC**: Generates Makefiles for Liquibook
- **Make**: Builds Liquibook and tests
- **CMake**: Available for main project (future use)

### Testing Strategy

- **Unit Tests**: 157 tests covering order book functionality
- **Performance Tests**: Latency and throughput measurements
- **Integration Tests**: Manual order entry and examples

## Contributing

1. **Fork the repository**
2. **Create a feature branch**
3. **Make your changes**
4. **Test thoroughly** (see TEST_SETUP.md)
5. **Submit a pull request**

### Development Guidelines

- Test changes with `make all` in `external/liquibook`
- Run unit tests: `bin/test/liquibook_unit_test`
- Update documentation in `TEST_SETUP.md` if needed

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details. 