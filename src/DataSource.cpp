#include "DataSource.hpp"
#include <random>
#include <time.h>

#include <fstream>
#include <float.h>
#include <vector>
#include <string>

#include <opencv2/opencv.hpp>
//#include <boost/tokenizer.hpp>


namespace DataSource{

    int process_mnist_images(const char * path, Matrix& Xtrain , Matrix& Ytrain,int nr_images=100 ){

        std::string str(path);	// convert char* to string

		const int width = 28;
		const int height = 28;
		const int LABELS = 10;
	
		for(int i=0; i < LABELS; i++){

			std::vector<cv::String> files;	// vector of strings to store file names

			cv::glob(path + std::to_string(i), files, true);
				// true means recursively read from path
			for(unsigned int k=0; k < (nr_images/LABELS); k++){
				cv::Mat img = cv::imread(files[k]);
				if(img.empty()) continue;	//only proceed further if the file is not empty
				Matrix* image = new Matrix(height*width,1);
				for(unsigned int h=0; h<height; h++){

					for(unsigned int w=0; w<width; w++){
						image->setPoids(h*width+w,1,(double)(img.at<uchar>(h,w)/255.0));
					}
				}
                Matrix f= *image;

				Xtrain.emplace_back(f);
				Matrix* vr = new  Matrix(LABELS, 1);				
				(*vr).setPoids(i,0, 1.0);
				Ytrain.emplace_back(*vr);
			}
		}
		return 0;

    }

/**
    int process_mnist_csv(const char* filename, Matrix & Xtrain, Matrix & Ytrain){

        std::string data(filename);
		ifstream in(data.c_str());

		if(!in.is_open()) return 1;

		typedef boost::tokenizer< boost::escaped_list_separator<char> > Tokenizer;
		std::vector<std::string> svec;
		std::string line;

		while(getline(in, line)){
			Tokenizer tok(line);
			auto it = tok.begin();
			int label = std::stoi(*it);
			Matrix labels(10, 1);
			labels[label] = 1.0;


			svec.assign(std::next(it, 1), tok.end());

			std::vector<double> dvec(svec.size());
			std::transform(svec.begin(), svec.end(), dvec.begin(), [](const std::string& val)
			{
				return (std::stod(val)/255); // divide by 255 for normalization, since each pixel is 8 bit
			});

			Xtrain.push_back(dvec);
			Ytrain.push_back(labels);
		}
		cout << "processed the input file" << endl;
		return 0;

    }

*/

}