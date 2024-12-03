# Aerial Image Processing - Edge Detection

## **Overview**

This project focuses on processing aerial images from the [USC SIPI Image Database](https://sipi.usc.edu/database/database.php?volume=aerials) using C++ and OpenCV. The main goal is to apply various image processing techniques to enhance the images and demonstrate the ability to handle large image datasets efficiently and perform Edge Detection.

---

## **Objectives**

- **Process a set of aerial images** using image processing techniques.
- **Demonstrate proficiency in C++ programming** and the use of OpenCV.
- **Efficiently handle and process a large number of images**.
- **Measure and analyze performance** of the processing pipeline.
- **Provide clear documentation** and instructions for reproducibility.

---

## **Data Used**

- **Dataset:** Aerial images from the [USC SIPI Image Database](https://sipi.usc.edu/database/database.php?volume=aerials). (100MB+)
- **Format:** High-resolution `.tiff` images of aerial photographs.
- **Number of Images:** 38 images of 10 MB each.

---

## **Image Processing Techniques Applied**

1. **Grayscale Conversion**
   - Converted color images to grayscale to simplify processing and reduce computational load.

2. **Histogram Equalization**
   - Enhanced image contrast to improve the visibility of features.

3. **Canny Edge Detection** (Optional)
   - Detected edges in the images to highlight boundaries and structures.

4. **Gaussian Blurring** (Optional)
   - Applied Gaussian blur to reduce noise and detail.

5. **Thresholding** (Optional)
   - Converted grayscale images to binary images based on a threshold value.

---

## **Project Structure**

```
CUDA_Independent_Project/
├── src/
│   └── main.cpp          # Main application code
├── build/                # Build directory (not included in the repository)
├── data/
│   └── aerials/          # Contains aerial images (downloaded separately)
├── results/              # Directory for processed images (created after running the program)
├── download_data.sh      # Script to download the aerial images
├── CMakeLists.txt        # Build configuration file for CMake
├── .gitignore            # Specifies intentionally untracked files to ignore
├── README.md             # Project documentation
└── execution_log.txt     # Console output demonstrating successful execution
```

---

## **Requirements**

- **Operating System:** Linux, macOS, or Windows
- **C++ Compiler:** Supports C++17 standard
  - **GCC:** Version 8.0 or higher
  - **Clang:** Version 7.0 or higher
  - **Visual Studio:** 2017 or higher
- **CMake:** Version 3.10 or higher
- **OpenCV:** Version 4.x installed on your system
- **Git:** For cloning the repository
- **Internet Connection:** To download the dataset

---

## **Setup and Installation**

### **1. Clone the Repository**

Open a terminal and run:

```bash
git clone https://github.com/your_username/CUDA-IP-Image-Processing.git
cd CUDA-IP-Image-Processing
```

Replace `your_username` with your GitHub username.

### **2. Obtain the Data**

The aerial images are not included in the repository due to their size. Use the provided script to download the images.

#### **2.1. Download the Data**

Make the script executable:

```bash
chmod +x download_data.sh
```

Run the script:

```bash
./download_data.sh
```

This script will:

- Create a `data/aerials/` directory if it doesn't exist.
- Download the aerial images from the USC SIPI Image Database.
- Save the images into the `data/aerials/` directory.

**Note:** Ensure you have `wget` installed. If not, install it using:

- **Ubuntu/Debian:**

  ```bash
  sudo apt-get install wget
  ```

- **macOS (with Homebrew):**

  ```bash
  brew install wget
  ```

### **3. Build the Project**

#### **3.1. Create a Build Directory**

It's good practice to build the project in a separate directory:

```bash
mkdir build
cd build
```

#### **3.2. Run CMake to Configure the Build**

```bash
cmake ..
```

#### **3.3. Compile the Project**

```bash
make
```

This will compile the code and create an executable named `main`.

---

## **How to Run**

From the `build/` directory, execute the program:

```bash
./main
```

**Default Behavior:**

- **Input Directory:** `../data/aerials/`
- **Output Directory:** `../results/`

**Using Command-Line Arguments:**

You can specify custom input and output directories:

```bash
./main <input_directory> <output_directory>
```

**Example:**

```bash
./main ../data/aerials ../results
```

---

## **Results and Verification**

- **Processed Images:**

  The processed images will be saved in the `results/` directory with filenames prefixed by `processed_`.

- **Verify the Results:**

  Open the images in an image viewer to verify that the processing has been applied correctly. You should notice:

  - Enhanced contrast due to histogram equalization.
  - (Optional) Edges highlighted if edge detection is enabled.
  - (Optional) Blurring effect if Gaussian blur is applied.
  - (Optional) Binary images if thresholding is applied.

---

## **Performance Metrics**

- **Total Processing Time:** Approximately **7.69 seconds** for 38 images on a standard machine.

- **Performance Measurement:**

  The program measures and outputs the total time taken to process all images, providing an indication of its efficiency.

- **Optimization:**

  - Efficient handling of large datasets by processing images in a loop.
  - Potential for further optimization using multithreading or GPU acceleration with CUDA.

---

## **Challenges Faced**

1. **Handling Large Files:**

   - **Issue:** GitHub's file size limitations prevented large image files from being included in the repository.
   - **Solution:** Excluded large files using `.gitignore` and provided a script to download them.

2. **Compatibility with C++17:**

   - **Issue:** The use of `std::string::ends_with` caused compilation errors since it's a C++20 feature.
   - **Solution:** Implemented a custom `endsWith` function to ensure compatibility with C++17.

3. **File Path Issues:**

   - **Issue:** Relative paths caused runtime errors when the program couldn't find the input directory.
   - **Solution:** Modified the code to accept command-line arguments for input and output directories and provided clear instructions.

4. **Git Merge Conflicts:**

   - **Issue:** Encountered conflicts when pushing to GitHub due to differences between local and remote branches.
   - **Solution:** Merged remote changes into the local branch, resolved conflicts, and successfully pushed the code.

---

## **Future Improvements**

- **GPU Acceleration with CUDA:**

  - Integrate CUDA to leverage GPU acceleration for faster processing times.

- **Multithreading:**

  - Implement multithreading to process multiple images concurrently.

- **Advanced Image Processing Techniques:**

  - Apply machine learning models for tasks like object detection or segmentation.

- **User Interface:**

  - Develop a graphical user interface (GUI) to allow users to interactively select processing options.

- **Error Handling and Logging:**

  - Enhance error handling to manage exceptions gracefully.
  - Implement logging mechanisms to record processing details and potential issues.

---

## **Conclusion**

This project successfully demonstrates the ability to process a large set of aerial images using C++ and OpenCV. By applying image processing techniques such as histogram equalization and edge detection, the images are enhanced to improve visibility and highlight important features. The project also showcases efficient handling of large datasets and provides a foundation for further exploration into advanced image processing and optimization techniques.

---
