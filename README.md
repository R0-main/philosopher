# Philosopher

`philo` is a C implementation of the classic Dining Philosophers concurrency
problem, written as part of the 42 curriculum. The project simulates a group of
philosophers who alternate between thinking, eating, and sleeping while sharing
a finite number of forks. Coordination is handled through POSIX threads,
mutexes, and a dedicated waiter that schedules access to forks to avoid
starvation.

## Features

- **Deterministic scheduling** – a waiter thread maintains a priority queue of
  philosophers asking for forks, granting access only when both forks are free.
- **Starvation detection** – each philosopher tracks their starvation timer and
  can signal the simulation to stop when a philosopher dies or everyone has met
  the required meal count.
- **Reusable timing utilities** – a lightweight timer module based on
  `gettimeofday(2)` powers action durations and can be reused in other projects.
- **Colorful runtime logs** – actions are reported in human-friendly logs to
  ease debugging and demonstration.

## Project Layout

```
├── Makefile                # Build rules for the executable and dependencies
├── dependencies/           # External libraries (ft_libc)
├── includes/               # Public headers (`philosopher.h`, `timer.h`)
├── src/
│   ├── forks/              # Fork creation, linking, and cleanup helpers
│   ├── lists/              # Doubly-linked list utilities for the waiter queue
│   ├── parsing/            # CLI argument validation and parsing
│   ├── philosophers/       # Philosopher lifecycle management and actions
│   ├── timer/              # Timer implementation used across the project
│   └── waiter/             # Waiter thread loop and fork arbitration
└── README.md
```

## Building

1. **Install prerequisites**
   - A POSIX-compliant system with `gcc`, `make`, and the pthread library
     available.
   - `git` access to clone the dependency [`ft_libc`](https://github.com/R0-main/ft_libc).

2. **Compile the project**

   ```bash
   make
   ```

   The Makefile fetches `ft_libc` (if missing) and produces the `philo`
   executable in the repository root. Use the convenience targets to clean
   generated artifacts:

   ```bash
   make clean   # remove object files
   make fclean  # remove objects and the executable
   make re      # rebuild from scratch
   ```

## Usage

```
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

All time values are expressed in milliseconds. The optional argument limits the
number of meals each philosopher must consume before the simulation ends. If the
argument is omitted, the simulation runs until a philosopher dies.

| Argument | Description |
| --- | --- |
| `number_of_philosophers` | Total philosophers seated at the table (also the number of forks). |
| `time_to_die` | Maximum time a philosopher can wait without eating before dying. |
| `time_to_eat` | Duration of the eating action once both forks are acquired. |
| `time_to_sleep` | Duration spent sleeping after eating. |
| `number_of_times_each_philosopher_must_eat` | (Optional) Stop condition when all philosophers have eaten this many times. |

### Example

```bash
./philo 5 800 200 200 3
```

Sample output (truncated for brevity):

```
🧑 Philosopher n°1 starts eating 🍔
🧑 Philosopher n°3 starts thinking 💭
🧑 Philosopher n°4 finished sleeping 💤
```

The simulation ends either when every philosopher reaches the required meal
count or when a philosopher dies from starvation.

## Code Examples

### Using the Timer Utility

```c
#include "timer.h"

void busy_wait_200ms(void)
{
    t_timer timer = {
        .duration = 200,
        .started = false,
    };

    start_timer(&timer);
    while (!is_timer_finished(&timer))
        ;
}
```

### Triggering Philosopher Actions

```c
#include "philosopher.h"

void set_philosopher_to_think(t_philosopher *philo, int think_time)
{
    trigger_action(philo, THINK, think_time);
    // Later in the loop, print_action(philo, false) can be used to announce the end.
}
```

These snippets demonstrate how to reuse the timer module independently and how
philosopher actions are driven internally.

## Development Tips

- Inspect `includes/philosopher.h` for a complete overview of available
  structures and helper functions.
- The waiter loop in `src/waiter/thread.c` is the central coordination point if
  you wish to experiment with alternative scheduling policies.
- Logs are emitted via `ft_fprintf`; customize `src/philosophers/say.c` to adjust
  formatting or integrate a different logging backend.

## License

This project follows the licensing terms defined by its original authors.
