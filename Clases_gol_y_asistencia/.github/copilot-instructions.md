# Copilot Instructions - Football Tournament Management System

## Project Overview
C++ console application managing a football tournament with administrative (CRUD operations) and operational (match results, statistics) areas. Uses file-based persistence with binary `.dat` files and manual memory management.

## Architecture Layers

### Core Entities (`include/` & `src/`)
- **`Persona.h/cpp`** - Base class for people (DNI, name, contact info, birthdate)
- **`Jugador.h/cpp`** - Extends Persona; adds position (1=Defender, 2=Midfielder, 3=Forward) and club ID
- **`Club.h/cpp`** - Club data with simple properties (ID, name, president, city)
- **`Partido.h/cpp`** - Match with local/away club IDs, goal counts, date, tournament ID
- **`Gol.h/cpp`** - Goal record (match number, player DNI, goal type: 1=Penalty, 2=Header, 3=Free kick)
- **`Asistencia.h/cpp`** - Assist record (match number, player DNI)
- **`Torneo.h/cpp`** - Tournament metadata (ID, name, year)
- **`Fecha.h/cpp`** - Date utility class (day/month/year)
- **`Posicion.h/cpp`** - League standings calculator (matches, wins, draws, losses, goals, points)

### Data Access Objects (Archive Classes)
- **`ArchivoClub.h/cpp`** - Manages clubs file; loads all into memory on init (`cargarDesdeArchivo()`)
- **`ArchivoJugador.h/cpp`** - Manages player file with CRUD and search
- **`ArchivoPartido.h/cpp`** - Manages matches; `registrarResultado()` prompts for goals/players, saves goals to file
- **`ArchivoGol.h/cpp`** - In-memory array pattern; loads/saves complete file via `cargarDesdeArchivo()` & `guardarEnArchivo()`
- **`Archivoasistencia.h/cpp`** - Similar to ArchivoGol; in-memory array for assists
- **`ArchivoTorneo.h/cpp`** - Tournament persistence; `crearFixture()` generates all match combinations

### UI Controllers
- **`MenuAdministrativo.cpp`** - CRUD menus for clubs (ops 1-5) and players (ops 6-9), fixture creation (op 10)
- **`MenuOperativo.cpp`** - Reports: match registration (op 1), standings (op 2), top scorers (op 3), top assists (op 4), fixture view (op 5)
- **`main.cpp`** - Entry point; main menu dispatches to admin/operative areas

## Key Data Patterns

### File I/O Strategy
- **Clubs & Players**: Read entire file → in-memory array (search by iteration)
- **Matches**: Direct file access with `fseek()` for updates
- **Goals & Assists**: Load-modify-save entire file atomically in-memory
- **File paths**: Hardcoded as `"clubes.dat"`, `"jugadores.dat"`, `"partidos.dat"`, `"goles.dat"`, `"asistencias.dat"`

### Search Pattern
- Club/Player searches iterate arrays or files; return `-1` if not found
- `ArchivoClub::buscarPorId()` returns pointer to in-memory object (can be null)
- `ArchivoPartido::registrarResultado()` searches by match number; updates via `fseek` + `fwrite`

### Data Integrity Conventions
- User enters `0` (or ID) to terminate input loops → returns false or early exit
- Delete operations use temp file pattern: read all except target, write to temp, rename
- No validation on player-club membership or goal scorer club verification

## Build & Execution
- **Compiler**: MinGW gcc/g++ (C:\\MinGW\\bin\\)
- **Build tasks**: `C/C++: gcc.exe compilar archivo activo` / `g++.exe` in VS Code
- **Include path**: `-I include`
- **Output**: `bin/Debug/` with `.exe` extension
- **Debug config**: `.vscode/launch.json` uses `gdb.exe` with pre-launch compilation

## Common Workflows

### Adding a New Feature
1. Define data class in `include/` with getters/setters
2. Create Archive class for file management
3. Add menu option in `MenuAdministrativo` or `MenuOperativo`
4. Compile via VS Code task

### Modifying Match Results
- Edit `ArchivoPartido::registrarResultado()` to change goal input flow
- Modify `ArchivoGol::agregarGol()` loop for validation

### Reporting Stats
- Model after `MenuOperativo`: load archive, iterate in-memory, sort/display
- Use `std::setw()` from `<iomanip>` for formatting (see top scorers/assists code)

## Technical Debt & Limitations
- No input validation on player DNI/club existence during goal registration
- Hardcoded filenames across multiple classes
- Manual memory management (new/delete) risks leaks if exceptions occur
- Goal type enumeration undefined (1, 2, 3 used without type constant)
- No separation of input validation (`Validaciones.h` only has `pedirEntero()`)

## File Organization
```
.github/copilot-instructions.md
include/        → 17 header files (entities + archives)
src/            → 17 implementation files
main.cpp        → Entry point
Clases.cbp      → CodeBlocks project file
.vscode/        → VS Code tasks, launch configs
bin/Debug/      → Compiled executables
```
