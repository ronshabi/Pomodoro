# C++ Pomodoro CLI

## Usage
```
pomodoro [session-length=25] [minutes-since-start=0]
```

## Features
- Simple text-file logging

    _By default, logs are saved to ~/.pomodoro_

- Print today's log as a CSV-formatted row to stdout
    ```
    pomodoro csv
    ```

- Utility to export all logs to CSV (see "utilities" directory)

## Install
- Clone the repository.
- Call ```cmake``` from your build directory.
- ```make && sudo make install```

_Replace make with your preferred generator (e.g. ninja)_

## Author
Ron Shabi