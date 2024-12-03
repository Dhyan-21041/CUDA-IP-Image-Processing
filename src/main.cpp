#include <iostream>
#include <string>
#include <vector>
#include <filesystem> // Requires C++17
#include <opencv2/opencv.hpp>

namespace fs = std::filesystem;

// Helper function to check if a string ends with a specific suffix
bool endsWith(const std::string &str, const std::string &suffix)
{
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

int main()
{
    // Directories
    std::string input_dir = "/home/coder/project/dataset/aerials";
    std::string output_dir = "/home/coder/project/results";

    // Create output directory if it doesn't exist
    if (!fs::exists(output_dir))
    {
        fs::create_directory(output_dir);
    }

    // List to store image file paths
    std::vector<std::string> image_paths;

    // Get all image files in the input directory
    for (const auto &entry : fs::directory_iterator(input_dir))
    {
        if (entry.is_regular_file())
        {
            std::string path = entry.path().string();
            // Check if the file is an image based on extension
            if (endsWith(path, ".tiff") || endsWith(path, ".tif") ||
                endsWith(path, ".jpg") || endsWith(path, ".png") ||
                endsWith(path, ".bmp"))
            {
                image_paths.push_back(path);
            }
        }
    }

    // Check if images are found
    if (image_paths.empty())
    {
        std::cerr << "No images found in " << input_dir << std::endl;
        return -1;
    }

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    // Processing images
    for (const auto &image_path : image_paths)
    {
        std::cout << "Processing: " << image_path << std::endl;

        // Load the image
        cv::Mat img = cv::imread(image_path);

        if (img.empty())
        {
            std::cerr << "Failed to load image: " << image_path << std::endl;
            continue;
        }

        // Convert to grayscale
        cv::Mat gray;
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

        // Apply histogram equalization
        cv::Mat equalized;
        cv::equalizeHist(gray, equalized);

        //(Optional) Apply Canny edge detection
        cv::Mat edges;
        double threshold1 = 50;
        double threshold2 = 150;
        cv::Canny(equalized, edges, threshold1, threshold2);

        //(Optional) Apply Gaussian blur
        cv::Mat blurred;
        cv::GaussianBlur(equalized, blurred, cv::Size(5, 5), 0);

        //(Optional) Apply thresholding
        cv::Mat thresholded;
        double thresh_value = 128;
        cv::threshold(equalized, thresholded, thresh_value, 255, cv::THRESH_BINARY);

        // Construct the output filename
        std::string filename = fs::path(image_path).filename().string();
        std::string output_path = output_dir + "/processed_" + filename;

        // Save the processed image (change 'equalized' to the variable you want to save)
        cv::imwrite(output_path, equalized);
    }

    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Processing complete in " << elapsed.count() << " seconds." << std::endl;

    return 0;
}
