#import acknex // similar to #include, but uses private/public system also: uses folders
#import default

// these are fuckers, how to solve this?
PANEL * pan_mainmenu = 
{
	digits(…);
	flags = 10;
}

public void foo() // is visible from the "outside" of this module
{
	error("hello, world!");
}

public int value; // is also visible

action foo() async // is spawned as an implicit coroutine when called (returns coro_handle instead of void)
{
	while(1)
	{
		my.pan += time_step; // ptr access is allowed by . as well as ->
		wait(1);
	}
}

void task(int count)
{
	for(int i = 0; i < count; i++)
	{
		diag("\ntask %d: %d", count, i);
		wait(1);
	}
}

function main()
{
	// will start 10 tasks that run concurrently (via coroutines)
	for(int i = 0; i < 10; i++) // allow declaration of variable here
	{
		coro_handle co = spawn task(i); // spawn will allow running synchronous routines as coroutines (similar to fork())
	}
	
	task(10); // will call synchronously

}
