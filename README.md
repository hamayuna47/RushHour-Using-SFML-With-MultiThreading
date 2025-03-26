# Rush Hour - Using SFML with MultiThreading

## Overview
Rush Hour is a C++ game developed using SFML (Simple and Fast Multimedia Library) with multi-threading to enhance performance and responsiveness. This game offers a dynamic and engaging experience where players navigate through traffic while avoiding obstacles and completing objectives.

## Features
- **Random Level Generation**: Each level is uniquely generated with different paths, starting points, and drop locations.
- **Randomized Characters**: Characters have distinct attributes and destinations, adding variety to gameplay.
- **Dynamic Obstacles**: Hurdles are randomly placed to challenge the player’s navigation skills.
- **Smooth Controls & Collision Detection**: Ensures a seamless gameplay experience.
- **Multi-threading Implementation**: Enhances game performance by handling AI, physics, and rendering separately.
- **Scoring System**: Players earn points based on successful deliveries and navigation efficiency.

## Technologies Used
- **C++**: Core programming language.
- **SFML**: Graphics and rendering library.
- **Multi-threading**: Optimized performance with concurrent execution.

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/RushHour-SFML.git
   ```
2. Navigate to the project directory:
   ```sh
   cd RushHour-SFML
   ```
3. Ensure SFML is installed on your system.
4. Compile the code:
   ```sh
   g++ main.cpp -o rushhour -lsfml-graphics -lsfml-window -lsfml-system -lpthread
   ```
5. Run the game:
   ```sh
   ./rushhour
   ```

## How to Play
1. **Start a New Game**: The game generates a random level with obstacles and objectives.
2. **Navigate the Traffic**: Use keyboard controls to maneuver through the roads.
3. **Complete Objectives**: Reach the destination while avoiding collisions.
4. **Earn Points**: Score based on performance and efficiency.

## Future Enhancements
- Adding AI-controlled traffic for increased difficulty.
- Enhanced UI with interactive menus.
- Additional game modes and challenges.

## Contributing
Contributions are welcome! Feel free to fork the repository, make improvements, and submit a pull request.

---
Developed by Humayun Abdullah

