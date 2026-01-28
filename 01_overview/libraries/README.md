# Static vs Dynamic Libraries

## Static Libraries (`.a`)
- Created using `ar` (archiver).
- Code is copied into the final executable at compile time.
- **Pros**: Executable is self-contained.
- **Cons**: Larger executable size; updating library requires re-compilation of the application.

## Dynamic Libraries (`.so` - Shared Object)
- Created using `gcc -shared`.
- Code is loaded at runtime.
- **Pros**: Smaller executables; multiple programs share memory for the library; easy updates.
- **Cons**: Dependency hell; runtime linking overhead (minimal).

## Usage
Run `make all` to build both.
Run `make run_static` to execute the statically linked program.
Run `make run_dynamic` to execute the dynamically linked program.
