# FlashConsole Library (version 0.1)

FlashConsole is a C++ library, currently in developpement, who can help you building a pretty user interface in console with ASCII character, you can create any type of interface (windows, menus, grids, lists, titles,...). You can place them in any postision using Horizontal alignement (left, center, right) and Vertical alignement (top, center, bottom)

## Installation

NOT READY

## Usage

```cpp
#include <FlashConsole>

// NOT READY
```

## Roadmap

FlashConsole (version 0.1) : Implementation of base objects
- Vector2 : Vector 2D (X,Y) who contain a base value and an offset to modify the value returned
- BaseInterface : Base class for creating every kind of interface, this object contain a key value pair list with an enum VectorType as the key and a shared pointer Vector2 as a value who contains the container size (Vector of the main window, currently the console window size or later the size of a BaseBox), the current content size, and the position set with two enums, HorizontalAlignement and VerticalAlignement

FlashConsole (version 0.2) : Continuing implementation of base objects
- BaseBox : Child of BaseInterface, with a list of other BaseInterface and BaseBox, this object is a BaseInteface who can contain others and positionate them correctly inside with specified parameters for the number of rows and cols
- Cleaning & Optimizing

FlashConsole (version 0.3) : Implementation of BaseInterface child objects

FlashConsole (version 0.4) : Implementation of BaseBox child objects

FlashConsole (version 0.5) : Implementation of Selection system

FlashConsole (version 0.6) : Implementation of Pattern design capable of automatizing, optimizing and upgrading the code and user experience

FlashConsole (version 0.7) : Optimisation for multi-platforms + extended ascii table

FlashConsole (version 1.0) : Official release, demos, exemples, documentation update,...



## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update optimize tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
