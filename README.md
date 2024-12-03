# Aerial Image Processing with OpenCV

## Overview

This project processes aerial images from the USC SIPI Image Database using OpenCV in C++. The main objective is to apply image processing techniques to enhance the images and demonstrate the ability to handle large datasets efficiently.

## Objectives

- Process a set of aerial images using image processing techniques.
- Demonstrate proficiency in C++ programming and use of OpenCV.
- Efficiently handle and process a large number of images.
- Provide performance metrics and proof of execution.

## Data Used

- **Dataset:** Aerial images from the [USC SIPI Image Database](https://sipi.usc.edu/database/database.php?volume=aerials).
- **Images:** Includes various `.tiff` images of aerial photographs.

## Image Processing Techniques Applied

1. **Grayscale Conversion:**
   - Converted color images to grayscale to simplify processing.

2. **Histogram Equalization:**
   - Enhanced the contrast of the images to bring out details.

3. **(Optional) Canny Edge Detection:**
   - Applied edge detection to highlight edges in the images.

4. **(Optional) Gaussian Blurring:**
   - Reduced image noise and detail by applying a Gaussian blur.

5. **(Optional) Thresholding:**
   - Converted grayscale images to binary images based on a threshold value.

## Project Structure

- `src/main.cpp`: The main application code.
- `CMakeLists.txt`: Build configuration file for CMake.
- `results/`: Contains sample processed images.
- `logs/execution_log.txt`: Console output demonstrating successful execution.
- `README.md`: Project documentation.

## How to Build and Run

### **Prerequisites**

- **C++ Compiler** with C++17 support.
- **OpenCV** installed on your system.
- **CMake** installed for building the project.

### **Building the Project**

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/your_username/your_repository.git
   cd your_repository
=======
# CUDA-IP-Image-Processing
>>>>>>> origin/main
