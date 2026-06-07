# 2D Graphics Editor

A simple 2D graphics editor written in C that allows users to draw and manipulate various geometric shapes on a text-based canvas.

## Features

- **Draw Line**: Draw lines between two points using Bresenham's line algorithm
- **Draw Rectangle**: Create rectangles with specified dimensions
- **Draw Triangle**: Draw triangles with three vertices
- **Draw Circle**: Create circles with specified center and radius
- **Delete Object**: Clear rectangular areas from the canvas
- **Modify Object**: Move or modify existing rectangles
- **Display Canvas**: View the current drawing
- **Exit**: Quit the application

## Canvas Specifications

- **Size**: 30 rows × 60 columns
- **Background**: Underscore character (`_`)
- **Drawing Character**: Asterisk (`*`)

## Compilation and Execution

### Compile
```bash
gcc -o graphics_editor graphics_editor.c -lm
```

### Run
```bash
./graphics_editor
```

## Usage

1. Run the program
2. Select an option from the menu (1-8)
3. Follow the prompts to enter coordinates or dimensions
4. Use option 7 to view your drawing
5. Use option 8 to exit

## Example Inputs

- **Line**: `x1=5, y1=5, x2=15, y2=20`
- **Rectangle**: `row=3, col=5, width=10, height=8`
- **Triangle**: `x1=10, y1=5, x2=20, y2=10, x3=15, y3=20`
- **Circle**: `center_row=15, center_col=30, radius=7`

## Technical Details

- Implements **Bresenham's line algorithm** for accurate line drawing
- Uses **2D array** for canvas representation
- All shapes drawn with bounds checking
