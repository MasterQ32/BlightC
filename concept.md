# Bright-C

Clone of the Lite-C language with some improvements over coroutine handling
and modularisation.

## Changes to coroutines

### Major changes

coroutines in Bright-C will not fork implicitly but must be explicitly spawned
with the keyword `async`:

```c
void foo(int i)
{
	async bar(i); // starts new coroutine
}
```

`async` returns a handle to the coroutine (`coro_handle`) so the user can finely
control when the coroutine will execute or end.

Marking a function with `async` will enforce the function to be always called
as a new coroutine:

```
void bar() async
{
	while(1)
	{
		wait(1);
	}
}

void foo()
{
	bar(); // will return coroutine handle instead of void
}
```

To enforce backwards compatibility, allow a compiler flag that will mark
all functions that include a call to `wait` as `async`.

Another keyword allows awaiting another coroutine: `await`.

```c
int foo() async
{
	for(int i = 0; i < 10; i++)
	{
		wait(1);
	}
	return 10;
}

void bar()
{
	int i = await foo();
}
```

`await` takes a single expression of the type `coro_handle` and waits for the
completion of this handle. It must be a running coroutine, otherwise a panic
will be thrown.

### coroutine api

```c
typedef /* opaque */ coro_handle;

// returns the handle to the current coroutine
coro_handle coro_current(); 

// sets the coroutine priority
// the higher the order, the later the coroutine will be called
void coro_set_order(coro_handle, int order);

// gets the coroutine order.
int coro_get_order(coro_handle);

// returns if the coroutine is still running
bool coro_running(coro_handle);

// stops the execution of the coroutine
bool coro_stop(coro_handle);
```

## Modularisation feature
Bright-C has a concept of "modules" whereas each module is defined in its own
file.

Each module may export a set of symbols (each functions and variables) and types with the
keyword `export`:

```c
publiexportc struct Player
{

};

export int player_health;

export int get_player_health()
{
	return player_health;
}
```

To use the symbols from another module, one can import the modul with the
function `#import`:

```c
#import acknex

function main()
{
	level_load(NULL);
}
```

The import name is defined by the file name. If a module is in a subdirectory,
the directory name can be prefixed with a `.` as a path separator. Thus, to
include the file `game/player.c`, you have to write `#import game.player`.

Modules can ring-reference each other without further work.

## Minor changes
- Introduction of boolean variables: `bool`, `true`, `false`
- Removal of non-obvious automatic casts
- struct copying
- struct initialization with list:
  ```c
  struct VECTOR { var x, y, z; };
  VECTOR a = { 10, 20, 30 };
  VECTOR b = { x=10, z=30 };
  ```
- Introduction of `const`ness
- Out-of-order declarations
- Introduction of `function pointers`
- Removal of "functions are pointers"
- Introduction of `nullptr` as `nullptr_t`
- Removal of implicit integer-pointer-casting (0 is not a pointer)
- introduction of unsigned types
- well-defined cast between `var` and a pointer
- remove C namespaces: no `enum foo` for an enum named `foo`. less typedefs are better

## Planned / Future Features

### Runtime Modules
Invoke the compiler at run time and receive a module handle with pointers
to the module exports.

Allows scripting…

### `defer` keyword
`defer <statement>` moves the execution of `<statement>` to the return point of
the function. If `defer` is used in a coroutine, the deferred statement is even
called when the coroutine is stopped externally.

This allows easier memory management.
