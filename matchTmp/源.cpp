///*#include <opencv2/core.hpp>
//#include <opencv2/imgcodecs.hpp>
//#include "opencv2/imgproc.hpp"
//#include <*/opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

#define GRAY_THRESH 160
#define HOUGH_VOTE 100

#include <map>

class RectComp
{
public:
	Rect rm;
	RectComp(Rect rms)
	{
		rm = rms;
	}
	bool operator < (const RectComp& ti) const
	{
		return rm.x< ti.rm.x;
	}
};

bool cmp1(const vector<Point> &a, const vector<Point> &b)
{
	return a[0].y < b[0].y;
}
bool cmp2(const vector<Point> &a, const vector<Point> &b)
{
	return a[0].x < b[0].x;
}
void compareData(vector<map<int, string>>& realAnswers){
	map<int, string>realAnswer;
	//1
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "D"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "A"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "DF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "D"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "C"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//2
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "D"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "A"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "A"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "DF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//3
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "DF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "D"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//4
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "DF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "A"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//5
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "DF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "D"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//6
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "BF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//7
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "D"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "DF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "D"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//8
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "D"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "DF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//9
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "D"));
	realAnswer.insert(pair<int, string>(3, "D"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "A"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "BF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "C"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//10
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "A"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "D"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "D"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "DF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "C"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "D"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "D"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//11
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "C"));
	realAnswer.insert(pair<int, string>(3, "D"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "C"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "DF"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "D"));
	realAnswer.insert(pair<int, string>(25, "A"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	/*
	data
	*/
}
void compareData3(vector<map<int, string>>& realAnswers){
	map<int, string>realAnswer;
	//1
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "A"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "D"));
	realAnswer.insert(pair<int, string>(8, "C"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "C"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "B"));
	realAnswer.insert(pair<int, string>(16, "C"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "B"));
	realAnswer.insert(pair<int, string>(41, "C"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "C"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswer.insert(pair<int, string>(46, "B"));
	realAnswer.insert(pair<int, string>(47, "C"));
	realAnswer.insert(pair<int, string>(48, "C"));
	realAnswer.insert(pair<int, string>(49, "C"));
	realAnswer.insert(pair<int, string>(50, "B"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "C"));
	realAnswer.insert(pair<int, string>(53, "C"));
	realAnswer.insert(pair<int, string>(54, "C"));
	realAnswer.insert(pair<int, string>(55, "A"));
	realAnswer.insert(pair<int, string>(56, "A"));
	realAnswer.insert(pair<int, string>(57, "D"));
	realAnswer.insert(pair<int, string>(58, "A"));
	realAnswer.insert(pair<int, string>(59, "D"));
	realAnswer.insert(pair<int, string>(60, "D"));
	realAnswer.insert(pair<int, string>(61, "D"));
	realAnswer.insert(pair<int, string>(62, "B"));
	realAnswer.insert(pair<int, string>(63, "C"));
	realAnswer.insert(pair<int, string>(64, "C"));
	realAnswer.insert(pair<int, string>(65, "B"));
	realAnswer.insert(pair<int, string>(66, "D"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "A"));
	realAnswer.insert(pair<int, string>(69, "C"));
	realAnswer.insert(pair<int, string>(70, "B"));
	realAnswer.insert(pair<int, string>(71, "C"));
	realAnswer.insert(pair<int, string>(72, "D"));
	realAnswer.insert(pair<int, string>(73, "B"));
	realAnswer.insert(pair<int, string>(74, "B"));
	realAnswer.insert(pair<int, string>(75, "A"));
	realAnswer.insert(pair<int, string>(76, "C"));
	realAnswer.insert(pair<int, string>(77, "B"));
	realAnswer.insert(pair<int, string>(78, "D"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "C"));
	realAnswer.insert(pair<int, string>(81, "B"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "B"));
	realAnswer.insert(pair<int, string>(84, "A"));
	realAnswer.insert(pair<int, string>(85, "D"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "D"));
	realAnswer.insert(pair<int, string>(88, "A"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "A"));
	realAnswer.insert(pair<int, string>(91, "D"));
	realAnswer.insert(pair<int, string>(92, "C"));
	realAnswer.insert(pair<int, string>(93, "B"));
	realAnswer.insert(pair<int, string>(94, "D"));
	realAnswer.insert(pair<int, string>(95, "A"));
	realAnswer.insert(pair<int, string>(96, "D"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "B"));
	realAnswer.insert(pair<int, string>(99, "A"));
	realAnswer.insert(pair<int, string>(100, "A"));
	realAnswer.insert(pair<int, string>(101, "B"));
	realAnswer.insert(pair<int, string>(102, "D"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "A"));
	realAnswer.insert(pair<int, string>(105, "C"));
	realAnswer.insert(pair<int, string>(106, "C"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "B"));
	realAnswer.insert(pair<int, string>(110, "C"));
	realAnswer.insert(pair<int, string>(111, "A"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "D"));
	realAnswer.insert(pair<int, string>(114, "B"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "A"));
	realAnswer.insert(pair<int, string>(117, "B"));
	realAnswer.insert(pair<int, string>(118, "A"));
	realAnswer.insert(pair<int, string>(119, "C"));
	realAnswer.insert(pair<int, string>(120, "B"));
	realAnswer.insert(pair<int, string>(121, "B"));
	realAnswer.insert(pair<int, string>(122, "A"));
	realAnswer.insert(pair<int, string>(123, "D"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "C"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "C"));
	realAnswer.insert(pair<int, string>(128, "B"));
	realAnswer.insert(pair<int, string>(129, "D"));
	realAnswer.insert(pair<int, string>(130, "D"));
	realAnswer.insert(pair<int, string>(131, "C"));
	realAnswer.insert(pair<int, string>(132, "B"));
	realAnswer.insert(pair<int, string>(133, "C"));
	realAnswer.insert(pair<int, string>(134, "B"));
	realAnswer.insert(pair<int, string>(135, "A"));
	realAnswer.insert(pair<int, string>(136, "BCD"));
	realAnswer.insert(pair<int, string>(137, "AB"));
	realAnswer.insert(pair<int, string>(138, "ABD"));
	realAnswer.insert(pair<int, string>(139, "AC"));
	realAnswer.insert(pair<int, string>(140, "BC"));
	realAnswer.insert(pair<int, string>(141, "ABC"));
	realAnswer.insert(pair<int, string>(142, "ABD"));
	realAnswer.insert(pair<int, string>(143, "BC"));
	realAnswer.insert(pair<int, string>(144, "AC"));
	realAnswer.insert(pair<int, string>(145, "AD"));
	realAnswer.insert(pair<int, string>(146, "ABD"));
	realAnswer.insert(pair<int, string>(147, "ACD"));
	realAnswer.insert(pair<int, string>(148, "CD"));
	realAnswer.insert(pair<int, string>(149, "BCD"));
	realAnswer.insert(pair<int, string>(150, "ABC"));
	realAnswer.insert(pair<int, string>(151, "CD"));
	realAnswer.insert(pair<int, string>(152, "BCD"));
	realAnswer.insert(pair<int, string>(153, "ACD"));
	realAnswer.insert(pair<int, string>(154, "ABD"));
	realAnswer.insert(pair<int, string>(155, "ABC"));
	realAnswer.insert(pair<int, string>(156, "ABCD"));
	realAnswer.insert(pair<int, string>(157, "ABCD"));
	realAnswer.insert(pair<int, string>(158, "ABD"));
	realAnswer.insert(pair<int, string>(159, "ABC"));
	realAnswer.insert(pair<int, string>(160, "ABCD"));
	realAnswer.insert(pair<int, string>(161, "BCD"));
	realAnswer.insert(pair<int, string>(162, "ABC"));
	realAnswer.insert(pair<int, string>(163, "BCD"));
	realAnswer.insert(pair<int, string>(164, "BC"));
	realAnswer.insert(pair<int, string>(165, "ABCD"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());
	/*
	data
	*/
	//2
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "D"));
	realAnswer.insert(pair<int, string>(8, "C"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "C"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "A"));
	realAnswer.insert(pair<int, string>(16, "D"));
	realAnswer.insert(pair<int, string>(17, "D"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "D"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "C"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "B"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "D"));
	realAnswer.insert(pair<int, string>(42, "A"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswer.insert(pair<int, string>(46, "B"));
	realAnswer.insert(pair<int, string>(47, "C"));
	realAnswer.insert(pair<int, string>(48, "A"));
	realAnswer.insert(pair<int, string>(49, "C"));
	realAnswer.insert(pair<int, string>(50, "B"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "C"));
	realAnswer.insert(pair<int, string>(53, "C"));
	realAnswer.insert(pair<int, string>(54, "C"));
	realAnswer.insert(pair<int, string>(55, "C"));
	realAnswer.insert(pair<int, string>(56, "A"));
	realAnswer.insert(pair<int, string>(57, "A"));
	realAnswer.insert(pair<int, string>(58, "D"));
	realAnswer.insert(pair<int, string>(59, "D"));
	realAnswer.insert(pair<int, string>(60, "D"));
	realAnswer.insert(pair<int, string>(61, "D"));
	realAnswer.insert(pair<int, string>(62, "D"));
	realAnswer.insert(pair<int, string>(63, "C"));
	realAnswer.insert(pair<int, string>(64, "B"));
	realAnswer.insert(pair<int, string>(65, "B"));
	realAnswer.insert(pair<int, string>(66, "D"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "B"));
	realAnswer.insert(pair<int, string>(69, "A"));
	realAnswer.insert(pair<int, string>(70, "A"));
	realAnswer.insert(pair<int, string>(71, "B"));
	realAnswer.insert(pair<int, string>(72, "C"));
	realAnswer.insert(pair<int, string>(73, "A"));
	realAnswer.insert(pair<int, string>(74, "D"));
	realAnswer.insert(pair<int, string>(75, "A"));
	realAnswer.insert(pair<int, string>(76, "C"));
	realAnswer.insert(pair<int, string>(77, "C"));
	realAnswer.insert(pair<int, string>(78, "D"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "C"));
	realAnswer.insert(pair<int, string>(81, "B"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "B"));
	realAnswer.insert(pair<int, string>(84, "D"));
	realAnswer.insert(pair<int, string>(85, "D"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "B"));
	realAnswer.insert(pair<int, string>(88, "A"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "A"));
	realAnswer.insert(pair<int, string>(91, "D"));
	realAnswer.insert(pair<int, string>(92, "B"));
	realAnswer.insert(pair<int, string>(93, "A"));
	realAnswer.insert(pair<int, string>(94, "D"));
	realAnswer.insert(pair<int, string>(95, "A"));
	realAnswer.insert(pair<int, string>(96, "D"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "B"));
	realAnswer.insert(pair<int, string>(99, "B"));
	realAnswer.insert(pair<int, string>(100,"B"));
	realAnswer.insert(pair<int, string>(101, "C"));
	realAnswer.insert(pair<int, string>(102, "C"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "A"));
	realAnswer.insert(pair<int, string>(105, "D"));
	realAnswer.insert(pair<int, string>(106, "A"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "B"));
	realAnswer.insert(pair<int, string>(110, "D"));
	realAnswer.insert(pair<int, string>(111, "B"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "D"));
	realAnswer.insert(pair<int, string>(114, "A"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "A"));
	realAnswer.insert(pair<int, string>(117, "B"));
	realAnswer.insert(pair<int, string>(118, "C"));
	realAnswer.insert(pair<int, string>(119, "C"));
	realAnswer.insert(pair<int, string>(120, "B"));
	realAnswer.insert(pair<int, string>(121, "A"));
	realAnswer.insert(pair<int, string>(122, "A"));
	realAnswer.insert(pair<int, string>(123, "D"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "C"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "C"));
	realAnswer.insert(pair<int, string>(128, "C"));
	realAnswer.insert(pair<int, string>(129, "C"));
	realAnswer.insert(pair<int, string>(130, "A"));
	realAnswer.insert(pair<int, string>(131, "C"));
	realAnswer.insert(pair<int, string>(132, "B"));
	realAnswer.insert(pair<int, string>(133, "C"));
	realAnswer.insert(pair<int, string>(134, "B"));
	realAnswer.insert(pair<int, string>(135, "A"));
	realAnswer.insert(pair<int, string>(136, "ACD"));
	realAnswer.insert(pair<int, string>(137, "ABC"));
	realAnswer.insert(pair<int, string>(138, "ABC"));
	realAnswer.insert(pair<int, string>(139, "ABC"));
	realAnswer.insert(pair<int, string>(140, "BC"));
	realAnswer.insert(pair<int, string>(141, "ACD"));
	realAnswer.insert(pair<int, string>(142, "ABD"));
	realAnswer.insert(pair<int, string>(143, "AB"));
	realAnswer.insert(pair<int, string>(144, "BD"));
	realAnswer.insert(pair<int, string>(145, "ABD"));
	realAnswer.insert(pair<int, string>(146, "ABD"));
	realAnswer.insert(pair<int, string>(147, "AD"));
	realAnswer.insert(pair<int, string>(148, "CD"));
	realAnswer.insert(pair<int, string>(149, "ABC"));
	realAnswer.insert(pair<int, string>(150, "ABC"));
	realAnswer.insert(pair<int, string>(151, "CD"));
	realAnswer.insert(pair<int, string>(152, "CD"));
	realAnswer.insert(pair<int, string>(153, "ACD"));
	realAnswer.insert(pair<int, string>(154, "ABD"));
	realAnswer.insert(pair<int, string>(155, "ABCD"));
	realAnswer.insert(pair<int, string>(156, "ABCD"));
	realAnswer.insert(pair<int, string>(157, "ABCD"));
	realAnswer.insert(pair<int, string>(158, "BD"));
	realAnswer.insert(pair<int, string>(159, "ABCD"));
	realAnswer.insert(pair<int, string>(160, "ACD"));
	realAnswer.insert(pair<int, string>(161, "BD"));
	realAnswer.insert(pair<int, string>(162, "ABC"));
	realAnswer.insert(pair<int, string>(163, "ABCD"));
	realAnswer.insert(pair<int, string>(164, "BC"));
	realAnswer.insert(pair<int, string>(165, "ABD"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//3
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "D"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "C"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "D"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "D"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "C"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "D"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "C"));
	realAnswer.insert(pair<int, string>(42, "C"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswer.insert(pair<int, string>(46, "B"));
	realAnswer.insert(pair<int, string>(47, "C"));
	realAnswer.insert(pair<int, string>(48, "B"));
	realAnswer.insert(pair<int, string>(49, "D"));
	realAnswer.insert(pair<int, string>(50, "B"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "A"));
	realAnswer.insert(pair<int, string>(53, "C"));
	realAnswer.insert(pair<int, string>(54, "C"));
	realAnswer.insert(pair<int, string>(55, "C"));
	realAnswer.insert(pair<int, string>(56, "A"));
	realAnswer.insert(pair<int, string>(57, "D"));
	realAnswer.insert(pair<int, string>(58, "D"));
	realAnswer.insert(pair<int, string>(59, "D"));
	realAnswer.insert(pair<int, string>(60, "D"));
	realAnswer.insert(pair<int, string>(61, "D"));
	realAnswer.insert(pair<int, string>(62, "A"));
	realAnswer.insert(pair<int, string>(63, "C"));
	realAnswer.insert(pair<int, string>(64, "C"));
	realAnswer.insert(pair<int, string>(65, "B"));
	realAnswer.insert(pair<int, string>(66, "D"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "B"));
	realAnswer.insert(pair<int, string>(69, "D"));
	realAnswer.insert(pair<int, string>(70, "B"));
	realAnswer.insert(pair<int, string>(71, "A"));
	realAnswer.insert(pair<int, string>(72, "D"));
	realAnswer.insert(pair<int, string>(73, "C"));
	realAnswer.insert(pair<int, string>(74, "B"));
	realAnswer.insert(pair<int, string>(75, "A"));
	realAnswer.insert(pair<int, string>(76, "C"));
	realAnswer.insert(pair<int, string>(77, "C"));
	realAnswer.insert(pair<int, string>(78, "D"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "C"));
	realAnswer.insert(pair<int, string>(81, "B"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "B"));
	realAnswer.insert(pair<int, string>(84, "D"));
	realAnswer.insert(pair<int, string>(85, "D"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "B"));
	realAnswer.insert(pair<int, string>(88, "A"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "D"));
	realAnswer.insert(pair<int, string>(91, "D"));
	realAnswer.insert(pair<int, string>(92, "B"));
	realAnswer.insert(pair<int, string>(93, "B"));
	realAnswer.insert(pair<int, string>(94, "D"));
	realAnswer.insert(pair<int, string>(95, "A"));
	realAnswer.insert(pair<int, string>(96, "D"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "B"));
	realAnswer.insert(pair<int, string>(99, "C"));
	realAnswer.insert(pair<int, string>(100, "D"));
	realAnswer.insert(pair<int, string>(101, "A"));
	realAnswer.insert(pair<int, string>(102, "B"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "D"));
	realAnswer.insert(pair<int, string>(105, "A"));
	realAnswer.insert(pair<int, string>(106, "C"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "B"));
	realAnswer.insert(pair<int, string>(110, "C"));
	realAnswer.insert(pair<int, string>(111, "A"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "D"));
	realAnswer.insert(pair<int, string>(114, "A"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "A"));
	realAnswer.insert(pair<int, string>(117, "B"));
	realAnswer.insert(pair<int, string>(118, "D"));
	realAnswer.insert(pair<int, string>(119, "C"));
	realAnswer.insert(pair<int, string>(120, "B"));
	realAnswer.insert(pair<int, string>(121, "B"));
	realAnswer.insert(pair<int, string>(122, "A"));
	realAnswer.insert(pair<int, string>(123, "D"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "C"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "C"));
	realAnswer.insert(pair<int, string>(128, "C"));
	realAnswer.insert(pair<int, string>(129, "C"));
	realAnswer.insert(pair<int, string>(130, "A"));
	realAnswer.insert(pair<int, string>(131, "C"));
	realAnswer.insert(pair<int, string>(132, "B"));
	realAnswer.insert(pair<int, string>(133, "D"));
	realAnswer.insert(pair<int, string>(134, "B"));
	realAnswer.insert(pair<int, string>(135, "A"));
	realAnswer.insert(pair<int, string>(136, "BCD"));
	realAnswer.insert(pair<int, string>(137, "BD"));
	realAnswer.insert(pair<int, string>(138, "ABCD"));
	realAnswer.insert(pair<int, string>(139, "ABC"));
	realAnswer.insert(pair<int, string>(140, "CD"));
	realAnswer.insert(pair<int, string>(141, "AC"));
	realAnswer.insert(pair<int, string>(142, "AB"));
	realAnswer.insert(pair<int, string>(143, "AB"));
	realAnswer.insert(pair<int, string>(144, "ABD"));
	realAnswer.insert(pair<int, string>(145, "AD"));
	realAnswer.insert(pair<int, string>(146, "ABD"));
	realAnswer.insert(pair<int, string>(147, "ABCD"));
	realAnswer.insert(pair<int, string>(148, "CD"));
	realAnswer.insert(pair<int, string>(149, "BC"));
	realAnswer.insert(pair<int, string>(150, "ABC"));
	realAnswer.insert(pair<int, string>(151, "CD"));
	realAnswer.insert(pair<int, string>(152, "BCD"));
	realAnswer.insert(pair<int, string>(153, "ACD"));
	realAnswer.insert(pair<int, string>(154, "ABCD"));
	realAnswer.insert(pair<int, string>(155, "BCD"));
	realAnswer.insert(pair<int, string>(156, "ABCD"));
	realAnswer.insert(pair<int, string>(157, "ACD"));
	realAnswer.insert(pair<int, string>(158, "ABC"));
	realAnswer.insert(pair<int, string>(159, "ABC"));
	realAnswer.insert(pair<int, string>(160, "ABD"));
	realAnswer.insert(pair<int, string>(161, "ABCD"));
	realAnswer.insert(pair<int, string>(162, "ABD"));
	realAnswer.insert(pair<int, string>(163, "ABCD"));
	realAnswer.insert(pair<int, string>(164, "ABC"));
	realAnswer.insert(pair<int, string>(165, "ABD"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//4
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "A"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "A"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "A"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "C"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "A"));
	realAnswer.insert(pair<int, string>(38, "D"));
	realAnswer.insert(pair<int, string>(39, "B"));
	realAnswer.insert(pair<int, string>(40, "C"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "C"));
	realAnswer.insert(pair<int, string>(43, "D"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswer.insert(pair<int, string>(46, "B"));
	realAnswer.insert(pair<int, string>(47, "C"));
	realAnswer.insert(pair<int, string>(48, "A"));
	realAnswer.insert(pair<int, string>(49, "C"));
	realAnswer.insert(pair<int, string>(50, "B"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "C"));
	realAnswer.insert(pair<int, string>(53, "A"));
	realAnswer.insert(pair<int, string>(54, "B"));
	realAnswer.insert(pair<int, string>(55, "C"));
	realAnswer.insert(pair<int, string>(56, "D"));
	realAnswer.insert(pair<int, string>(57, "C"));
	realAnswer.insert(pair<int, string>(58, "D"));
	realAnswer.insert(pair<int, string>(59, "C"));
	realAnswer.insert(pair<int, string>(60, "D"));
	realAnswer.insert(pair<int, string>(61, "C"));
	realAnswer.insert(pair<int, string>(62, "C"));
	realAnswer.insert(pair<int, string>(63, "A"));
	realAnswer.insert(pair<int, string>(64, "B"));
	realAnswer.insert(pair<int, string>(65, "D"));
	realAnswer.insert(pair<int, string>(66, "A"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "A"));
	realAnswer.insert(pair<int, string>(69, "B"));
	realAnswer.insert(pair<int, string>(70, "A"));
	realAnswer.insert(pair<int, string>(71, "D"));
	realAnswer.insert(pair<int, string>(72, "C"));
	realAnswer.insert(pair<int, string>(73, "B"));
	realAnswer.insert(pair<int, string>(74, "D"));
	realAnswer.insert(pair<int, string>(75, "A"));
	realAnswer.insert(pair<int, string>(76, "A"));
	realAnswer.insert(pair<int, string>(77, "C"));
	realAnswer.insert(pair<int, string>(78, "A"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "A"));
	realAnswer.insert(pair<int, string>(81, "C"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "B"));
	realAnswer.insert(pair<int, string>(84, "B"));
	realAnswer.insert(pair<int, string>(85, "D"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "D"));
	realAnswer.insert(pair<int, string>(88, "B"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "C"));
	realAnswer.insert(pair<int, string>(91, "B"));
	realAnswer.insert(pair<int, string>(92, "D"));
	realAnswer.insert(pair<int, string>(93, "B"));
	realAnswer.insert(pair<int, string>(94, "D"));
	realAnswer.insert(pair<int, string>(95, "B"));
	realAnswer.insert(pair<int, string>(96, "D"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "C"));
	realAnswer.insert(pair<int, string>(99, "A"));
	realAnswer.insert(pair<int, string>(100, "D"));
	realAnswer.insert(pair<int, string>(101, "D"));
	realAnswer.insert(pair<int, string>(102, "B"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "D"));
	realAnswer.insert(pair<int, string>(105, "A"));
	realAnswer.insert(pair<int, string>(106, "C"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "B"));
	realAnswer.insert(pair<int, string>(110, "D"));
	realAnswer.insert(pair<int, string>(111, "B"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "D"));
	realAnswer.insert(pair<int, string>(114, "A"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "A"));
	realAnswer.insert(pair<int, string>(117, "D"));
	realAnswer.insert(pair<int, string>(118, "D"));
	realAnswer.insert(pair<int, string>(119, "B"));
	realAnswer.insert(pair<int, string>(120, "A"));
	realAnswer.insert(pair<int, string>(121, "B"));
	realAnswer.insert(pair<int, string>(122, "A"));
	realAnswer.insert(pair<int, string>(123, "D"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "C"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "D"));
	realAnswer.insert(pair<int, string>(128, "C"));
	realAnswer.insert(pair<int, string>(129, "C"));
	realAnswer.insert(pair<int, string>(130, "A"));
	realAnswer.insert(pair<int, string>(131, "D"));
	realAnswer.insert(pair<int, string>(132, "A"));
	realAnswer.insert(pair<int, string>(133, "B"));
	realAnswer.insert(pair<int, string>(134, "B"));
	realAnswer.insert(pair<int, string>(135, "A"));
	realAnswer.insert(pair<int, string>(136, "BCD"));
	realAnswer.insert(pair<int, string>(137, "ABC"));
	realAnswer.insert(pair<int, string>(138, "ABD"));
	realAnswer.insert(pair<int, string>(139, "AC"));
	realAnswer.insert(pair<int, string>(140, "BCD"));
	realAnswer.insert(pair<int, string>(141, "AC"));
	realAnswer.insert(pair<int, string>(142, "ABD"));
	realAnswer.insert(pair<int, string>(143, "BD"));
	realAnswer.insert(pair<int, string>(144, "ABC"));
	realAnswer.insert(pair<int, string>(145, "ABC"));
	realAnswer.insert(pair<int, string>(146, "AC"));
	realAnswer.insert(pair<int, string>(147, "AD"));
	realAnswer.insert(pair<int, string>(148, "ACD"));
	realAnswer.insert(pair<int, string>(149, "ABCD"));
	realAnswer.insert(pair<int, string>(150, "AC"));
	realAnswer.insert(pair<int, string>(151, "BC"));
	realAnswer.insert(pair<int, string>(152, "BCD"));
	realAnswer.insert(pair<int, string>(153, "ABC"));
	realAnswer.insert(pair<int, string>(154, "ABD"));
	realAnswer.insert(pair<int, string>(155, "BC"));
	realAnswer.insert(pair<int, string>(156, "ABCD"));
	realAnswer.insert(pair<int, string>(157, "AB"));
	realAnswer.insert(pair<int, string>(158, "AC"));
	realAnswer.insert(pair<int, string>(159, "ACD"));
	realAnswer.insert(pair<int, string>(160, "ABD"));
	realAnswer.insert(pair<int, string>(161, "ABD"));
	realAnswer.insert(pair<int, string>(162, "ABD"));
	realAnswer.insert(pair<int, string>(163, "ABCD"));
	realAnswer.insert(pair<int, string>(164, "ABCD"));
	realAnswer.insert(pair<int, string>(165, "ABCD"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//5
	realAnswer.insert(pair<int, string>(1, "B"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "A"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "C"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "D"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "A"));
	realAnswer.insert(pair<int, string>(18, "A"));
	realAnswer.insert(pair<int, string>(19, "D"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "A"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "C"));
	realAnswer.insert(pair<int, string>(24, "D"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "D"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "A"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "A"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "B"));
	realAnswer.insert(pair<int, string>(43, "C"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswer.insert(pair<int, string>(46, "B"));
	realAnswer.insert(pair<int, string>(47, "A"));
	realAnswer.insert(pair<int, string>(48, "D"));
	realAnswer.insert(pair<int, string>(49, "D"));
	realAnswer.insert(pair<int, string>(50, "B"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "C"));
	realAnswer.insert(pair<int, string>(53, "A"));
	realAnswer.insert(pair<int, string>(54, "C"));
	realAnswer.insert(pair<int, string>(55, "C"));
	realAnswer.insert(pair<int, string>(56, "D"));
	realAnswer.insert(pair<int, string>(57, "D"));
	realAnswer.insert(pair<int, string>(58, "B"));
	realAnswer.insert(pair<int, string>(59, "D"));
	realAnswer.insert(pair<int, string>(60, "B"));
	realAnswer.insert(pair<int, string>(61, "C"));
	realAnswer.insert(pair<int, string>(62, "D"));
	realAnswer.insert(pair<int, string>(63, "C"));
	realAnswer.insert(pair<int, string>(64, "A"));
	realAnswer.insert(pair<int, string>(65, "B"));
	realAnswer.insert(pair<int, string>(66, "D"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "B"));
	realAnswer.insert(pair<int, string>(69, "D"));
	realAnswer.insert(pair<int, string>(70, "A"));
	realAnswer.insert(pair<int, string>(71, "B"));
	realAnswer.insert(pair<int, string>(72, "C"));
	realAnswer.insert(pair<int, string>(73, "A"));
	realAnswer.insert(pair<int, string>(74, "D"));
	realAnswer.insert(pair<int, string>(75, "B"));
	realAnswer.insert(pair<int, string>(76, "C"));
	realAnswer.insert(pair<int, string>(77, "C"));
	realAnswer.insert(pair<int, string>(78, "D"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "C"));
	realAnswer.insert(pair<int, string>(81, "B"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "B"));
	realAnswer.insert(pair<int, string>(84, "D"));
	realAnswer.insert(pair<int, string>(85, "D"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "B"));
	realAnswer.insert(pair<int, string>(88, "A"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "C"));
	realAnswer.insert(pair<int, string>(91, "D"));
	realAnswer.insert(pair<int, string>(92, "C"));
	realAnswer.insert(pair<int, string>(93, "D"));
	realAnswer.insert(pair<int, string>(94, "D"));
	realAnswer.insert(pair<int, string>(95, "B"));
	realAnswer.insert(pair<int, string>(96, "D"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "B"));
	realAnswer.insert(pair<int, string>(99, "D"));
	realAnswer.insert(pair<int, string>(100, "B"));
	realAnswer.insert(pair<int, string>(101, "A"));
	realAnswer.insert(pair<int, string>(102, "C"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "B"));
	realAnswer.insert(pair<int, string>(105, "B"));
	realAnswer.insert(pair<int, string>(106, "C"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "B"));
	realAnswer.insert(pair<int, string>(110, "D"));
	realAnswer.insert(pair<int, string>(111, "A"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "C"));
	realAnswer.insert(pair<int, string>(114, "A"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "A"));
	realAnswer.insert(pair<int, string>(117, "B"));
	realAnswer.insert(pair<int, string>(118, "A"));
	realAnswer.insert(pair<int, string>(119, "C"));
	realAnswer.insert(pair<int, string>(120, "B"));
	realAnswer.insert(pair<int, string>(121, "A"));
	realAnswer.insert(pair<int, string>(122, "A"));
	realAnswer.insert(pair<int, string>(123, "D"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "C"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "B"));
	realAnswer.insert(pair<int, string>(128, "D"));
	realAnswer.insert(pair<int, string>(129, "C"));
	realAnswer.insert(pair<int, string>(130, "A"));
	realAnswer.insert(pair<int, string>(131, "C"));
	realAnswer.insert(pair<int, string>(132, "B"));
	realAnswer.insert(pair<int, string>(133, "C"));
	realAnswer.insert(pair<int, string>(134, "D"));
	realAnswer.insert(pair<int, string>(135, "A"));
	realAnswer.insert(pair<int, string>(136, "ABCD"));
	realAnswer.insert(pair<int, string>(137, "BCD"));
	realAnswer.insert(pair<int, string>(138, "AD"));
	realAnswer.insert(pair<int, string>(139, "AB"));
	realAnswer.insert(pair<int, string>(140, "BCD"));
	realAnswer.insert(pair<int, string>(141, "CD"));
	realAnswer.insert(pair<int, string>(142, "AB"));
	realAnswer.insert(pair<int, string>(143, "ABD"));
	realAnswer.insert(pair<int, string>(144, "ABCD"));
	realAnswer.insert(pair<int, string>(145, "ABCD"));
	realAnswer.insert(pair<int, string>(146, "AB"));
	realAnswer.insert(pair<int, string>(147, "ACD"));
	realAnswer.insert(pair<int, string>(148, "CD"));
	realAnswer.insert(pair<int, string>(149, "ACD"));
	realAnswer.insert(pair<int, string>(150, "ABCD"));
	realAnswer.insert(pair<int, string>(151, "CD"));
	realAnswer.insert(pair<int, string>(152, "AC"));
	realAnswer.insert(pair<int, string>(153, "ABC"));
	realAnswer.insert(pair<int, string>(154, "ACD"));
	realAnswer.insert(pair<int, string>(155, "BD"));
	realAnswer.insert(pair<int, string>(156, "ABCD"));
	realAnswer.insert(pair<int, string>(157, "BD"));
	realAnswer.insert(pair<int, string>(158, "BC"));
	realAnswer.insert(pair<int, string>(159, "ABC"));
	realAnswer.insert(pair<int, string>(160, "ACD"));
	realAnswer.insert(pair<int, string>(161, "BCD"));
	realAnswer.insert(pair<int, string>(162, "AB"));
	realAnswer.insert(pair<int, string>(163, "BC"));
	realAnswer.insert(pair<int, string>(164, "ACD"));
	realAnswer.insert(pair<int, string>(165, "ABD"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//6
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "A"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "D"));
	realAnswer.insert(pair<int, string>(8, "A"));
	realAnswer.insert(pair<int, string>(9, "D"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "C"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "A"));
	realAnswer.insert(pair<int, string>(16, "C"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "A"));
	realAnswer.insert(pair<int, string>(19, "D"));
	realAnswer.insert(pair<int, string>(20, "D"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "C"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "A"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "D"));
	realAnswer.insert(pair<int, string>(39, "B"));
	realAnswer.insert(pair<int, string>(40, "A"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "A"));
	realAnswer.insert(pair<int, string>(43, "A"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "A"));
	realAnswer.insert(pair<int, string>(46, "C"));
	realAnswer.insert(pair<int, string>(47, "C"));
	realAnswer.insert(pair<int, string>(48, "B"));
	realAnswer.insert(pair<int, string>(49, "C"));
	realAnswer.insert(pair<int, string>(50, "B"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "C"));
	realAnswer.insert(pair<int, string>(53, "A"));
	realAnswer.insert(pair<int, string>(54, "C"));
	realAnswer.insert(pair<int, string>(55, "A"));
	realAnswer.insert(pair<int, string>(56, "A"));
	realAnswer.insert(pair<int, string>(57, "C"));
	realAnswer.insert(pair<int, string>(58, "D"));
	realAnswer.insert(pair<int, string>(59, "C"));
	realAnswer.insert(pair<int, string>(60, "D"));
	realAnswer.insert(pair<int, string>(61, "D"));
	realAnswer.insert(pair<int, string>(62, "B"));
	realAnswer.insert(pair<int, string>(63, "C"));
	realAnswer.insert(pair<int, string>(64, "B"));
	realAnswer.insert(pair<int, string>(65, "B"));
	realAnswer.insert(pair<int, string>(66, "D"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "B"));
	realAnswer.insert(pair<int, string>(69, "D"));
	realAnswer.insert(pair<int, string>(70, "A"));
	realAnswer.insert(pair<int, string>(71, "B"));
	realAnswer.insert(pair<int, string>(72, "C"));
	realAnswer.insert(pair<int, string>(73, "B"));
	realAnswer.insert(pair<int, string>(74, "D"));
	realAnswer.insert(pair<int, string>(75, "C"));
	realAnswer.insert(pair<int, string>(76, "C"));
	realAnswer.insert(pair<int, string>(77, "C"));
	realAnswer.insert(pair<int, string>(78, "D"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "D"));
	realAnswer.insert(pair<int, string>(81, "B"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "B"));
	realAnswer.insert(pair<int, string>(84, "D"));
	realAnswer.insert(pair<int, string>(85, "C"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "B"));
	realAnswer.insert(pair<int, string>(88, "A"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "A"));
	realAnswer.insert(pair<int, string>(91, "D"));
	realAnswer.insert(pair<int, string>(92, "C"));
	realAnswer.insert(pair<int, string>(93, "A"));
	realAnswer.insert(pair<int, string>(94, "C"));
	realAnswer.insert(pair<int, string>(95, "B"));
	realAnswer.insert(pair<int, string>(96, "A"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "B"));
	realAnswer.insert(pair<int, string>(99, "A"));
	realAnswer.insert(pair<int, string>(100, "B"));
	realAnswer.insert(pair<int, string>(101, "A"));
	realAnswer.insert(pair<int, string>(102, "B"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "A"));
	realAnswer.insert(pair<int, string>(105, "A"));
	realAnswer.insert(pair<int, string>(106, "A"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "B"));
	realAnswer.insert(pair<int, string>(110, "CD"));
	realAnswer.insert(pair<int, string>(111, "A"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "A"));
	realAnswer.insert(pair<int, string>(114, "A"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "A"));
	realAnswer.insert(pair<int, string>(117, "B"));
	realAnswer.insert(pair<int, string>(118, "D"));
	realAnswer.insert(pair<int, string>(119, "C"));
	realAnswer.insert(pair<int, string>(120, "A"));
	realAnswer.insert(pair<int, string>(121, "B"));
	realAnswer.insert(pair<int, string>(122, "A"));
	realAnswer.insert(pair<int, string>(123, "D"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "C"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "C"));
	realAnswer.insert(pair<int, string>(128, "C"));
	realAnswer.insert(pair<int, string>(129, "D"));
	realAnswer.insert(pair<int, string>(130, "A"));
	realAnswer.insert(pair<int, string>(131, "C"));
	realAnswer.insert(pair<int, string>(132, "B"));
	realAnswer.insert(pair<int, string>(133, "C"));
	realAnswer.insert(pair<int, string>(134, "B"));
	realAnswer.insert(pair<int, string>(135, "D"));
	realAnswer.insert(pair<int, string>(136, "BC"));
	realAnswer.insert(pair<int, string>(137, "ABC"));
	realAnswer.insert(pair<int, string>(138, "ABC"));
	realAnswer.insert(pair<int, string>(139, "ABC"));
	realAnswer.insert(pair<int, string>(140, "BC"));
	realAnswer.insert(pair<int, string>(141, "AB"));
	realAnswer.insert(pair<int, string>(142, "ABD"));
	realAnswer.insert(pair<int, string>(143, "ABC"));
	realAnswer.insert(pair<int, string>(144, "ACD"));
	realAnswer.insert(pair<int, string>(145, "AB"));
	realAnswer.insert(pair<int, string>(146, "AB"));
	realAnswer.insert(pair<int, string>(147, "AC"));
	realAnswer.insert(pair<int, string>(148, "CD"));
	realAnswer.insert(pair<int, string>(149, "BCD"));
	realAnswer.insert(pair<int, string>(150, "AB"));
	realAnswer.insert(pair<int, string>(151, "ABC"));
	realAnswer.insert(pair<int, string>(152, "BCD"));
	realAnswer.insert(pair<int, string>(153, "ACD"));
	realAnswer.insert(pair<int, string>(154, "ABD"));
	realAnswer.insert(pair<int, string>(155, "AB"));
	realAnswer.insert(pair<int, string>(156, "ACD"));
	realAnswer.insert(pair<int, string>(157, "BC"));
	realAnswer.insert(pair<int, string>(158, "BCD"));
	realAnswer.insert(pair<int, string>(159, "ABD"));
	realAnswer.insert(pair<int, string>(160, "ABD"));
	realAnswer.insert(pair<int, string>(161, "ABD"));
	realAnswer.insert(pair<int, string>(162, "ACD"));
	realAnswer.insert(pair<int, string>(163, "BCD"));
	realAnswer.insert(pair<int, string>(164, "BC"));
	realAnswer.insert(pair<int, string>(165, "ABCD"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());



	//7
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "A"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "D"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "C"));
	realAnswer.insert(pair<int, string>(13, "A"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "A"));
	realAnswer.insert(pair<int, string>(16, "C"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "C"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "D"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "C"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "D"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "B"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "C"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "A"));
	realAnswer.insert(pair<int, string>(46, "B"));
	realAnswer.insert(pair<int, string>(47, "B"));
	realAnswer.insert(pair<int, string>(48, "C"));
	realAnswer.insert(pair<int, string>(49, "C"));
	realAnswer.insert(pair<int, string>(50, "A"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "C"));
	realAnswer.insert(pair<int, string>(53, "A"));
	realAnswer.insert(pair<int, string>(54, "C"));
	realAnswer.insert(pair<int, string>(55, "C"));
	realAnswer.insert(pair<int, string>(56, "A"));
	realAnswer.insert(pair<int, string>(57, "D"));
	realAnswer.insert(pair<int, string>(58, "D"));
	realAnswer.insert(pair<int, string>(59, "A"));
	realAnswer.insert(pair<int, string>(60, "D"));
	realAnswer.insert(pair<int, string>(61, "D"));
	realAnswer.insert(pair<int, string>(62, "B"));
	realAnswer.insert(pair<int, string>(63, "C"));
	realAnswer.insert(pair<int, string>(64, "C"));
	realAnswer.insert(pair<int, string>(65, "B"));
	realAnswer.insert(pair<int, string>(66, "D"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "B"));
	realAnswer.insert(pair<int, string>(69, "D"));
	realAnswer.insert(pair<int, string>(70, "C"));
	realAnswer.insert(pair<int, string>(71, "C"));
	realAnswer.insert(pair<int, string>(72, "A"));
	realAnswer.insert(pair<int, string>(73, "A"));
	realAnswer.insert(pair<int, string>(74, "D"));
	realAnswer.insert(pair<int, string>(75, "A"));
	realAnswer.insert(pair<int, string>(76, "A"));
	realAnswer.insert(pair<int, string>(77, "C"));
	realAnswer.insert(pair<int, string>(78, "A"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "C"));
	realAnswer.insert(pair<int, string>(81, "B"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "B"));
	realAnswer.insert(pair<int, string>(84, "D"));
	realAnswer.insert(pair<int, string>(85, "D"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "B"));
	realAnswer.insert(pair<int, string>(88, "A"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "A"));
	realAnswer.insert(pair<int, string>(91, "D"));
	realAnswer.insert(pair<int, string>(92, "C"));
	realAnswer.insert(pair<int, string>(93, "B"));
	realAnswer.insert(pair<int, string>(94, "D"));
	realAnswer.insert(pair<int, string>(95, "A"));
	realAnswer.insert(pair<int, string>(96, "D"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "B"));
	realAnswer.insert(pair<int, string>(99, "B"));
	realAnswer.insert(pair<int, string>(100, "B"));
	realAnswer.insert(pair<int, string>(101, "C"));
	realAnswer.insert(pair<int, string>(102, "B"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "A"));
	realAnswer.insert(pair<int, string>(105, "A"));
	realAnswer.insert(pair<int, string>(106, "A"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "B"));
	realAnswer.insert(pair<int, string>(110, "C"));
	realAnswer.insert(pair<int, string>(111, "A"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "D"));
	realAnswer.insert(pair<int, string>(114, "B"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "D"));
	realAnswer.insert(pair<int, string>(117, "B"));
	realAnswer.insert(pair<int, string>(118, "A"));
	realAnswer.insert(pair<int, string>(119, "C"));
	realAnswer.insert(pair<int, string>(120, "B"));
	realAnswer.insert(pair<int, string>(121, "B"));
	realAnswer.insert(pair<int, string>(122, "A"));
	realAnswer.insert(pair<int, string>(123, "B"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "C"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "C"));
	realAnswer.insert(pair<int, string>(128, "C"));
	realAnswer.insert(pair<int, string>(129, "D"));
	realAnswer.insert(pair<int, string>(130, "A"));
	realAnswer.insert(pair<int, string>(131, "C"));
	realAnswer.insert(pair<int, string>(132, "B"));
	realAnswer.insert(pair<int, string>(133, "B"));
	realAnswer.insert(pair<int, string>(134, "B"));
	realAnswer.insert(pair<int, string>(135, "A"));
	realAnswer.insert(pair<int, string>(136, "AC"));
	realAnswer.insert(pair<int, string>(137, "AB"));
	realAnswer.insert(pair<int, string>(138, "ABD"));
	realAnswer.insert(pair<int, string>(139, "ABC"));
	realAnswer.insert(pair<int, string>(140, "BC"));
	realAnswer.insert(pair<int, string>(141, "AC"));
	realAnswer.insert(pair<int, string>(142, "ABD"));
	realAnswer.insert(pair<int, string>(143, "ABD"));
	realAnswer.insert(pair<int, string>(144, "ACD"));
	realAnswer.insert(pair<int, string>(145, "ABD"));
	realAnswer.insert(pair<int, string>(146, "AB"));
	realAnswer.insert(pair<int, string>(147, "ACD"));
	realAnswer.insert(pair<int, string>(148, "CD"));
	realAnswer.insert(pair<int, string>(149, "BCD"));
	realAnswer.insert(pair<int, string>(150, "ABC"));
	realAnswer.insert(pair<int, string>(151, "CD"));
	realAnswer.insert(pair<int, string>(152, "BC"));
	realAnswer.insert(pair<int, string>(153, "ABCD"));
	realAnswer.insert(pair<int, string>(154, "ABD"));
	realAnswer.insert(pair<int, string>(155, "ABD"));
	realAnswer.insert(pair<int, string>(156, "ABCD"));
	realAnswer.insert(pair<int, string>(157, "ABCD"));
	realAnswer.insert(pair<int, string>(158, "ABD"));
	realAnswer.insert(pair<int, string>(159, "AB"));
	realAnswer.insert(pair<int, string>(160, "ABD"));
	realAnswer.insert(pair<int, string>(161, "BD"));
	realAnswer.insert(pair<int, string>(162, "AB"));
	realAnswer.insert(pair<int, string>(163, "ABCD"));
	realAnswer.insert(pair<int, string>(164, "BC"));
	realAnswer.insert(pair<int, string>(165, "AB"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//8
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "A"));
	realAnswer.insert(pair<int, string>(9, "D"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "D"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "A"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "A"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "C"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "C"));
	realAnswer.insert(pair<int, string>(43, "C"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswer.insert(pair<int, string>(46, "C"));
	realAnswer.insert(pair<int, string>(47, "B"));
	realAnswer.insert(pair<int, string>(48, "C"));
	realAnswer.insert(pair<int, string>(49, "C"));
	realAnswer.insert(pair<int, string>(50, "A"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "B"));
	realAnswer.insert(pair<int, string>(53, "C"));
	realAnswer.insert(pair<int, string>(54, "C"));
	realAnswer.insert(pair<int, string>(55, "C"));
	realAnswer.insert(pair<int, string>(56, "A"));
	realAnswer.insert(pair<int, string>(57, "D"));
	realAnswer.insert(pair<int, string>(58, "D"));
	realAnswer.insert(pair<int, string>(59, "D"));
	realAnswer.insert(pair<int, string>(60, "B"));
	realAnswer.insert(pair<int, string>(61, "D"));
	realAnswer.insert(pair<int, string>(62, "D"));
	realAnswer.insert(pair<int, string>(63, "C"));
	realAnswer.insert(pair<int, string>(64, "B"));
	realAnswer.insert(pair<int, string>(65, "B"));
	realAnswer.insert(pair<int, string>(66, "D"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "A"));
	realAnswer.insert(pair<int, string>(69, "A"));
	realAnswer.insert(pair<int, string>(70, "B"));
	realAnswer.insert(pair<int, string>(71, "A"));
	realAnswer.insert(pair<int, string>(72, "D"));
	realAnswer.insert(pair<int, string>(73, "A"));
	realAnswer.insert(pair<int, string>(74, "B"));
	realAnswer.insert(pair<int, string>(75, "A"));
	realAnswer.insert(pair<int, string>(76, "C"));
	realAnswer.insert(pair<int, string>(77, "C"));
	realAnswer.insert(pair<int, string>(78, "D"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "C"));
	realAnswer.insert(pair<int, string>(81, "B"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "B"));
	realAnswer.insert(pair<int, string>(84, "B"));
	realAnswer.insert(pair<int, string>(85, "D"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "B"));
	realAnswer.insert(pair<int, string>(88, "A"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "A"));
	realAnswer.insert(pair<int, string>(91, "D"));
	realAnswer.insert(pair<int, string>(92, "A"));
	realAnswer.insert(pair<int, string>(93, "B"));
	realAnswer.insert(pair<int, string>(94, "D"));
	realAnswer.insert(pair<int, string>(95, "A"));
	realAnswer.insert(pair<int, string>(96, "D"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "B"));
	realAnswer.insert(pair<int, string>(99, "D"));
	realAnswer.insert(pair<int, string>(100, "D"));
	realAnswer.insert(pair<int, string>(101, "B"));
	realAnswer.insert(pair<int, string>(102, "B"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "D"));
	realAnswer.insert(pair<int, string>(105, "B"));
	realAnswer.insert(pair<int, string>(106, "B"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "B"));
	realAnswer.insert(pair<int, string>(110, "D"));
	realAnswer.insert(pair<int, string>(111, "A"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "C"));
	realAnswer.insert(pair<int, string>(114, "A"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "A"));
	realAnswer.insert(pair<int, string>(117, "B"));
	realAnswer.insert(pair<int, string>(118, "A"));
	realAnswer.insert(pair<int, string>(119, "C"));
	realAnswer.insert(pair<int, string>(120, "B"));
	realAnswer.insert(pair<int, string>(121, "D"));
	realAnswer.insert(pair<int, string>(122, "C"));
	realAnswer.insert(pair<int, string>(123, "C"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "B"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "C"));
	realAnswer.insert(pair<int, string>(128, "C"));
	realAnswer.insert(pair<int, string>(129, "D"));
	realAnswer.insert(pair<int, string>(130, "D"));
	realAnswer.insert(pair<int, string>(131, "C"));
	realAnswer.insert(pair<int, string>(132, "B"));
	realAnswer.insert(pair<int, string>(133, "D"));
	realAnswer.insert(pair<int, string>(134, "B"));
	realAnswer.insert(pair<int, string>(135, "A"));
	realAnswer.insert(pair<int, string>(136, "BCD"));
	realAnswer.insert(pair<int, string>(137, "AB"));
	realAnswer.insert(pair<int, string>(138, "ABD"));
	realAnswer.insert(pair<int, string>(139, "ABC"));
	realAnswer.insert(pair<int, string>(140, "BC"));
	realAnswer.insert(pair<int, string>(141, "ABC"));
	realAnswer.insert(pair<int, string>(142, "ABD"));
	realAnswer.insert(pair<int, string>(143, "AB"));
	realAnswer.insert(pair<int, string>(144, "ACD"));
	realAnswer.insert(pair<int, string>(145, "AD"));
	realAnswer.insert(pair<int, string>(146, "AB"));
	realAnswer.insert(pair<int, string>(147, "ACD"));
	realAnswer.insert(pair<int, string>(148, "CD"));
	realAnswer.insert(pair<int, string>(149, "BC"));
	realAnswer.insert(pair<int, string>(150, "ABC"));
	realAnswer.insert(pair<int, string>(151, "CD"));
	realAnswer.insert(pair<int, string>(152, "BCD"));
	realAnswer.insert(pair<int, string>(153, "ACD"));
	realAnswer.insert(pair<int, string>(154, "AD"));
	realAnswer.insert(pair<int, string>(155, "ABC"));
	realAnswer.insert(pair<int, string>(156, "ABCD"));
	realAnswer.insert(pair<int, string>(157, "ABCD"));
	realAnswer.insert(pair<int, string>(158, "ABC"));
	realAnswer.insert(pair<int, string>(159, "ABD"));
	realAnswer.insert(pair<int, string>(160, "ABD"));
	realAnswer.insert(pair<int, string>(161, "ACD"));
	realAnswer.insert(pair<int, string>(162, "ABD"));
	realAnswer.insert(pair<int, string>(163, "ABC"));
	realAnswer.insert(pair<int, string>(164, "BC"));
	realAnswer.insert(pair<int, string>(165, "ABCD"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//9
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "D"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "B"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "C"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "A"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "D"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "D"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "A"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "B"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "C"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswer.insert(pair<int, string>(46, "B"));
	realAnswer.insert(pair<int, string>(47, "C"));
	realAnswer.insert(pair<int, string>(48, "C"));
	realAnswer.insert(pair<int, string>(49, "D"));
	realAnswer.insert(pair<int, string>(50, "B"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "C"));
	realAnswer.insert(pair<int, string>(53, "C"));
	realAnswer.insert(pair<int, string>(54, "C"));
	realAnswer.insert(pair<int, string>(55, "C"));
	realAnswer.insert(pair<int, string>(56, "A"));
	realAnswer.insert(pair<int, string>(57, "D"));
	realAnswer.insert(pair<int, string>(58, "D"));
	realAnswer.insert(pair<int, string>(59, "D"));
	realAnswer.insert(pair<int, string>(60, "D"));
	realAnswer.insert(pair<int, string>(61, "D"));
	realAnswer.insert(pair<int, string>(62, "A"));
	realAnswer.insert(pair<int, string>(63, "C"));
	realAnswer.insert(pair<int, string>(64, "B"));
	realAnswer.insert(pair<int, string>(65, "B"));
	realAnswer.insert(pair<int, string>(66, "D"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "B"));
	realAnswer.insert(pair<int, string>(69, "D"));
	realAnswer.insert(pair<int, string>(70, "B"));
	realAnswer.insert(pair<int, string>(71, "A"));
	realAnswer.insert(pair<int, string>(72, "D"));
	realAnswer.insert(pair<int, string>(73, "C"));
	realAnswer.insert(pair<int, string>(74, "B"));
	realAnswer.insert(pair<int, string>(75, "C"));
	realAnswer.insert(pair<int, string>(76, "C"));
	realAnswer.insert(pair<int, string>(77, "C"));
	realAnswer.insert(pair<int, string>(78, "D"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "C"));
	realAnswer.insert(pair<int, string>(81, "B"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "B"));
	realAnswer.insert(pair<int, string>(84, "D"));
	realAnswer.insert(pair<int, string>(85, "D"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "B"));
	realAnswer.insert(pair<int, string>(88, "A"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "A"));
	realAnswer.insert(pair<int, string>(91, "D"));
	realAnswer.insert(pair<int, string>(92, "D"));
	realAnswer.insert(pair<int, string>(93, "B"));
	realAnswer.insert(pair<int, string>(94, "D"));
	realAnswer.insert(pair<int, string>(95, "A"));
	realAnswer.insert(pair<int, string>(96, "D"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "B"));
	realAnswer.insert(pair<int, string>(99, "D"));
	realAnswer.insert(pair<int, string>(100, "D"));
	realAnswer.insert(pair<int, string>(101, "A"));
	realAnswer.insert(pair<int, string>(102, "B"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "A"));
	realAnswer.insert(pair<int, string>(105, "D"));
	realAnswer.insert(pair<int, string>(106, "C"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "B"));
	realAnswer.insert(pair<int, string>(110, "D"));
	realAnswer.insert(pair<int, string>(111, "A"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "D"));
	realAnswer.insert(pair<int, string>(114, "B"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "A"));
	realAnswer.insert(pair<int, string>(117, "B"));
	realAnswer.insert(pair<int, string>(118, "A"));
	realAnswer.insert(pair<int, string>(119, "B"));
	realAnswer.insert(pair<int, string>(120, "B"));
	realAnswer.insert(pair<int, string>(121, "A"));
	realAnswer.insert(pair<int, string>(122, "A"));
	realAnswer.insert(pair<int, string>(123, "D"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "C"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "C"));
	realAnswer.insert(pair<int, string>(128, "C"));
	realAnswer.insert(pair<int, string>(129, "C"));
	realAnswer.insert(pair<int, string>(130, "A"));
	realAnswer.insert(pair<int, string>(131, "C"));
	realAnswer.insert(pair<int, string>(132, "B"));
	realAnswer.insert(pair<int, string>(133, "A"));
	realAnswer.insert(pair<int, string>(134, "B"));
	realAnswer.insert(pair<int, string>(135, "C"));
	realAnswer.insert(pair<int, string>(136, "ABCD"));
	realAnswer.insert(pair<int, string>(137, "AB"));
	realAnswer.insert(pair<int, string>(138, "ABD"));
	realAnswer.insert(pair<int, string>(139, "ABC"));
	realAnswer.insert(pair<int, string>(140, "ABC"));
	realAnswer.insert(pair<int, string>(141, "BC"));
	realAnswer.insert(pair<int, string>(142, "ABD"));
	realAnswer.insert(pair<int, string>(143, "AB"));
	realAnswer.insert(pair<int, string>(144, "ABCD"));
	realAnswer.insert(pair<int, string>(145, "AC"));
	realAnswer.insert(pair<int, string>(146, "ABD"));
	realAnswer.insert(pair<int, string>(147, "ACD"));
	realAnswer.insert(pair<int, string>(148, "CD"));
	realAnswer.insert(pair<int, string>(149, "BCD"));
	realAnswer.insert(pair<int, string>(150, "ABC"));
	realAnswer.insert(pair<int, string>(151, "CD"));
	realAnswer.insert(pair<int, string>(152, "BCD"));
	realAnswer.insert(pair<int, string>(153, "ACD"));
	realAnswer.insert(pair<int, string>(154, "AD"));
	realAnswer.insert(pair<int, string>(155, "BCD"));
	realAnswer.insert(pair<int, string>(156, "ABCD"));
	realAnswer.insert(pair<int, string>(157, "BCD"));
	realAnswer.insert(pair<int, string>(158, "ABD"));
	realAnswer.insert(pair<int, string>(159, "ABC"));
	realAnswer.insert(pair<int, string>(160, "ABD"));
	realAnswer.insert(pair<int, string>(161, "BCD"));
	realAnswer.insert(pair<int, string>(162, "ACD"));
	realAnswer.insert(pair<int, string>(163, "BCD"));
	realAnswer.insert(pair<int, string>(164, "BC"));
	realAnswer.insert(pair<int, string>(165, "ABD"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//10
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "D"));
	realAnswer.insert(pair<int, string>(8, "A"));
	realAnswer.insert(pair<int, string>(9, "D"));
	realAnswer.insert(pair<int, string>(10, "B"));
	realAnswer.insert(pair<int, string>(11, "D"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "A"));
	realAnswer.insert(pair<int, string>(16, "C"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "A"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "A"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "A"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "D"));
	realAnswer.insert(pair<int, string>(30, "B"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "A"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "B"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "A"));
	realAnswer.insert(pair<int, string>(46, "B"));
	realAnswer.insert(pair<int, string>(47, "C"));
	realAnswer.insert(pair<int, string>(48, "A"));
	realAnswer.insert(pair<int, string>(49, "C"));
	realAnswer.insert(pair<int, string>(50, "B"));
	realAnswer.insert(pair<int, string>(51, "D"));
	realAnswer.insert(pair<int, string>(52, "C"));
	realAnswer.insert(pair<int, string>(53, "C"));
	realAnswer.insert(pair<int, string>(54, "B"));
	realAnswer.insert(pair<int, string>(55, "C"));
	realAnswer.insert(pair<int, string>(56, "B"));
	realAnswer.insert(pair<int, string>(57, "A"));
	realAnswer.insert(pair<int, string>(58, "A"));
	realAnswer.insert(pair<int, string>(59, "C"));
	realAnswer.insert(pair<int, string>(60, "D"));
	realAnswer.insert(pair<int, string>(61, "C"));
	realAnswer.insert(pair<int, string>(62, "D"));
	realAnswer.insert(pair<int, string>(63, "A"));
	realAnswer.insert(pair<int, string>(64, "C"));
	realAnswer.insert(pair<int, string>(65, "B"));
	realAnswer.insert(pair<int, string>(66, "D"));
	realAnswer.insert(pair<int, string>(67, "C"));
	realAnswer.insert(pair<int, string>(68, "B"));
	realAnswer.insert(pair<int, string>(69, "D"));
	realAnswer.insert(pair<int, string>(70, "A"));
	realAnswer.insert(pair<int, string>(71, "B"));
	realAnswer.insert(pair<int, string>(72, "C"));
	realAnswer.insert(pair<int, string>(73, "B"));
	realAnswer.insert(pair<int, string>(74, "D"));
	realAnswer.insert(pair<int, string>(75, "A"));
	realAnswer.insert(pair<int, string>(76, "C"));
	realAnswer.insert(pair<int, string>(77, "C"));
	realAnswer.insert(pair<int, string>(78, "D"));
	realAnswer.insert(pair<int, string>(79, "A"));
	realAnswer.insert(pair<int, string>(80, "C"));
	realAnswer.insert(pair<int, string>(81, "B"));
	realAnswer.insert(pair<int, string>(82, "C"));
	realAnswer.insert(pair<int, string>(83, "C"));
	realAnswer.insert(pair<int, string>(84, "D"));
	realAnswer.insert(pair<int, string>(85, "D"));
	realAnswer.insert(pair<int, string>(86, "C"));
	realAnswer.insert(pair<int, string>(87, "B"));
	realAnswer.insert(pair<int, string>(88, "A"));
	realAnswer.insert(pair<int, string>(89, "C"));
	realAnswer.insert(pair<int, string>(90, "C"));
	realAnswer.insert(pair<int, string>(91, "D"));
	realAnswer.insert(pair<int, string>(92, "A"));
	realAnswer.insert(pair<int, string>(93, "B"));
	realAnswer.insert(pair<int, string>(94, "D"));
	realAnswer.insert(pair<int, string>(95, "B"));
	realAnswer.insert(pair<int, string>(96, "D"));
	realAnswer.insert(pair<int, string>(97, "D"));
	realAnswer.insert(pair<int, string>(98, "B"));
	realAnswer.insert(pair<int, string>(99, "B"));
	realAnswer.insert(pair<int, string>(100, "A"));
	realAnswer.insert(pair<int, string>(101, "B"));
	realAnswer.insert(pair<int, string>(102, "D"));
	realAnswer.insert(pair<int, string>(103, "D"));
	realAnswer.insert(pair<int, string>(104, "B"));
	realAnswer.insert(pair<int, string>(105, "A"));
	realAnswer.insert(pair<int, string>(106, "C"));
	realAnswer.insert(pair<int, string>(107, "A"));
	realAnswer.insert(pair<int, string>(108, "A"));
	realAnswer.insert(pair<int, string>(109, "D"));
	realAnswer.insert(pair<int, string>(110, "D"));
	realAnswer.insert(pair<int, string>(111, "A"));
	realAnswer.insert(pair<int, string>(112, "B"));
	realAnswer.insert(pair<int, string>(113, "D"));
	realAnswer.insert(pair<int, string>(114, "A"));
	realAnswer.insert(pair<int, string>(115, "C"));
	realAnswer.insert(pair<int, string>(116, "A"));
	realAnswer.insert(pair<int, string>(117, "B"));
	realAnswer.insert(pair<int, string>(118, "B"));
	realAnswer.insert(pair<int, string>(119, "D"));
	realAnswer.insert(pair<int, string>(120, "A"));
	realAnswer.insert(pair<int, string>(121, "B"));
	realAnswer.insert(pair<int, string>(122, "D"));
	realAnswer.insert(pair<int, string>(123, "C"));
	realAnswer.insert(pair<int, string>(124, "A"));
	realAnswer.insert(pair<int, string>(125, "C"));
	realAnswer.insert(pair<int, string>(126, "A"));
	realAnswer.insert(pair<int, string>(127, "C"));
	realAnswer.insert(pair<int, string>(128, "C"));
	realAnswer.insert(pair<int, string>(129, "C"));
	realAnswer.insert(pair<int, string>(130, "A"));
	realAnswer.insert(pair<int, string>(131, "C"));
	realAnswer.insert(pair<int, string>(132, "B"));
	realAnswer.insert(pair<int, string>(133, "C"));
	realAnswer.insert(pair<int, string>(134, "B"));
	realAnswer.insert(pair<int, string>(135, "A"));
	realAnswer.insert(pair<int, string>(136, "ACD"));
	realAnswer.insert(pair<int, string>(137, "ABC"));
	realAnswer.insert(pair<int, string>(138, "ABD"));
	realAnswer.insert(pair<int, string>(139, "AC"));
	realAnswer.insert(pair<int, string>(140, "BCD"));
	realAnswer.insert(pair<int, string>(141, "BC"));
	realAnswer.insert(pair<int, string>(142, "ABC"));
	realAnswer.insert(pair<int, string>(143, "AB"));
	realAnswer.insert(pair<int, string>(144, "BCD"));
	realAnswer.insert(pair<int, string>(145, "ABC"));
	realAnswer.insert(pair<int, string>(146, "AB"));
	realAnswer.insert(pair<int, string>(147, "ABD"));
	realAnswer.insert(pair<int, string>(148, "CD"));
	realAnswer.insert(pair<int, string>(149, "ABC"));
	realAnswer.insert(pair<int, string>(150, "ABC"));
	realAnswer.insert(pair<int, string>(151, "CD"));
	realAnswer.insert(pair<int, string>(152, "BCD"));
	realAnswer.insert(pair<int, string>(153, "ACD"));
	realAnswer.insert(pair<int, string>(154, "ABD"));
	realAnswer.insert(pair<int, string>(155, "BCD"));
	realAnswer.insert(pair<int, string>(156, "ABC"));
	realAnswer.insert(pair<int, string>(157, "ABCD"));
	realAnswer.insert(pair<int, string>(158, "AC"));
	realAnswer.insert(pair<int, string>(159, "ABD"));
	realAnswer.insert(pair<int, string>(160, "ABC"));
	realAnswer.insert(pair<int, string>(161, "BCD"));
	realAnswer.insert(pair<int, string>(162, "ABC"));
	realAnswer.insert(pair<int, string>(163, "BC"));
	realAnswer.insert(pair<int, string>(164, "BC"));
	realAnswer.insert(pair<int, string>(165, "ABCD"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());
}

void compareData2(vector<map<int, string>>& realAnswers){
	map<int, string>realAnswer;
	//1
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "C"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "A"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "D"));
	realAnswer.insert(pair<int, string>(12, "C"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "D"));
	realAnswer.insert(pair<int, string>(16, "C"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "C"));
	realAnswer.insert(pair<int, string>(24, "D"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "D"));
	realAnswer.insert(pair<int, string>(27, "D"));
	realAnswer.insert(pair<int, string>(28, "C"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "D"));
	realAnswer.insert(pair<int, string>(32, "D"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "C"));
	realAnswer.insert(pair<int, string>(35, "C"));
	realAnswer.insert(pair<int, string>(36, "C"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "C"));
	realAnswer.insert(pair<int, string>(43, "C"));
	realAnswer.insert(pair<int, string>(44, "B"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//2
	realAnswer.insert(pair<int, string>(1, "B"));
	realAnswer.insert(pair<int, string>(2, "C"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "A"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "A"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "D"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "D"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "B"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "B"));
	realAnswer.insert(pair<int, string>(31, "A"));
	realAnswer.insert(pair<int, string>(32, "D"));
	realAnswer.insert(pair<int, string>(33, "A"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "D"));
	realAnswer.insert(pair<int, string>(36, "C"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "A"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "B"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//3
	realAnswer.insert(pair<int, string>(1, "B"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "D"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "A"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "B"));
	realAnswer.insert(pair<int, string>(11, "A"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "D"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "C"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "D"));
	realAnswer.insert(pair<int, string>(19, "A"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "D"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "D"));
	realAnswer.insert(pair<int, string>(25, "D"));
	realAnswer.insert(pair<int, string>(26, "A"));
	realAnswer.insert(pair<int, string>(27, "D"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "D"));
	realAnswer.insert(pair<int, string>(33, "B"));
	realAnswer.insert(pair<int, string>(34, "D"));
	realAnswer.insert(pair<int, string>(35, "A"));
	realAnswer.insert(pair<int, string>(36, "B"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "A"));
	realAnswer.insert(pair<int, string>(40, "B"));
	realAnswer.insert(pair<int, string>(41, "C"));
	realAnswer.insert(pair<int, string>(42, "A"));
	realAnswer.insert(pair<int, string>(43, "D"));
	realAnswer.insert(pair<int, string>(44, "B"));
	realAnswer.insert(pair<int, string>(45, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//4
	realAnswer.insert(pair<int, string>(1, "A"));
	realAnswer.insert(pair<int, string>(2, "A"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "B"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "B"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "B"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "D"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "D"));
	realAnswer.insert(pair<int, string>(25, "D"));
	realAnswer.insert(pair<int, string>(26, "D"));
	realAnswer.insert(pair<int, string>(27, "D"));
	realAnswer.insert(pair<int, string>(28, "D"));
	realAnswer.insert(pair<int, string>(29, "D"));
	realAnswer.insert(pair<int, string>(30, "D"));
	realAnswer.insert(pair<int, string>(31, "D"));
	realAnswer.insert(pair<int, string>(32, "D"));
	realAnswer.insert(pair<int, string>(33, "D"));
	realAnswer.insert(pair<int, string>(34, "D"));
	realAnswer.insert(pair<int, string>(35, "D"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "D"));
	realAnswer.insert(pair<int, string>(38, "D"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "D"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "D"));
	realAnswer.insert(pair<int, string>(44, "D"));
	realAnswer.insert(pair<int, string>(45, "D"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//5
	realAnswer.insert(pair<int, string>(1, "A"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "C"));
	realAnswer.insert(pair<int, string>(6, "D"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "A"));
	realAnswer.insert(pair<int, string>(10, "C"));
	realAnswer.insert(pair<int, string>(11, "A"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "D"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "D"));
	realAnswer.insert(pair<int, string>(19, "A"));
	realAnswer.insert(pair<int, string>(20, "B"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "D"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "A"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "A"));
	realAnswer.insert(pair<int, string>(27, "A"));
	realAnswer.insert(pair<int, string>(28, "C"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "D"));
	realAnswer.insert(pair<int, string>(31, "A"));
	realAnswer.insert(pair<int, string>(32, "D"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "D"));
	realAnswer.insert(pair<int, string>(35, "D"));
	realAnswer.insert(pair<int, string>(36, "B"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "B"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "A"));
	realAnswer.insert(pair<int, string>(42, "C"));
	realAnswer.insert(pair<int, string>(43, "A"));
	realAnswer.insert(pair<int, string>(44, "B"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());
}
void compareData4(vector<map<int, string>>& realAnswers){
	map<int, string>realAnswer;

	//1
	realAnswer.insert(pair<int, string>(1, "B"));
	realAnswer.insert(pair<int, string>(2, "C"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "A"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "A"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "D"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "D"));
	realAnswer.insert(pair<int, string>(26, "D"));
	realAnswer.insert(pair<int, string>(27, "A"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "D"));
	realAnswer.insert(pair<int, string>(32, "B"));
	realAnswer.insert(pair<int, string>(33, "B"));
	realAnswer.insert(pair<int, string>(34, "C"));
	realAnswer.insert(pair<int, string>(35, "D"));
	realAnswer.insert(pair<int, string>(36, "B"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "B"));
	realAnswer.insert(pair<int, string>(40, "C"));
	realAnswer.insert(pair<int, string>(41, "D"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "C"));
	realAnswer.insert(pair<int, string>(45, "D"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//2
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "A"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "A"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "B"));
	realAnswer.insert(pair<int, string>(11, "A"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "D"));
	realAnswer.insert(pair<int, string>(14, "C"));
	realAnswer.insert(pair<int, string>(15, "A"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "A"));
	realAnswer.insert(pair<int, string>(18, "C"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "D"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "A"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "D"));
	realAnswer.insert(pair<int, string>(25, "A"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "D"));
	realAnswer.insert(pair<int, string>(29, "A"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "B"));
	realAnswer.insert(pair<int, string>(33, "B"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "A"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "C"));
	realAnswer.insert(pair<int, string>(40, "C"));
	realAnswer.insert(pair<int, string>(41, "A"));
	realAnswer.insert(pair<int, string>(42, "B"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//3
	realAnswer.insert(pair<int, string>(1, "B"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "A"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "A"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "A"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "D"));
	realAnswer.insert(pair<int, string>(16, "A"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "A"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "D"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "D"));
	realAnswer.insert(pair<int, string>(23, "A"));
	realAnswer.insert(pair<int, string>(24, "C"));
	realAnswer.insert(pair<int, string>(25, "D"));
	realAnswer.insert(pair<int, string>(26, "D"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "D"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "B"));
	realAnswer.insert(pair<int, string>(33, "A"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "D"));
	realAnswer.insert(pair<int, string>(36, "B"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "A"));
	realAnswer.insert(pair<int, string>(40, "C"));
	realAnswer.insert(pair<int, string>(41, "A"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "C"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//4
	realAnswer.insert(pair<int, string>(1, "B"));
	realAnswer.insert(pair<int, string>(2, "A"));
	realAnswer.insert(pair<int, string>(3, "A"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "D"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "C"));
	realAnswer.insert(pair<int, string>(8, "A"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "A"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "C"));
	realAnswer.insert(pair<int, string>(14, "D"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "C"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "D"));
	realAnswer.insert(pair<int, string>(19, "A"));
	realAnswer.insert(pair<int, string>(20, "B"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "A"));
	realAnswer.insert(pair<int, string>(25, "A"));
	realAnswer.insert(pair<int, string>(26, "A"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "D"));
	realAnswer.insert(pair<int, string>(31, "D"));
	realAnswer.insert(pair<int, string>(32, "A"));
	realAnswer.insert(pair<int, string>(33, "B"));
	realAnswer.insert(pair<int, string>(34, "C"));
	realAnswer.insert(pair<int, string>(35, "A"));
	realAnswer.insert(pair<int, string>(36, "C"));
	realAnswer.insert(pair<int, string>(37, "A"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "C"));
	realAnswer.insert(pair<int, string>(40, "A"));
	realAnswer.insert(pair<int, string>(41, "D"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "A"));
	realAnswer.insert(pair<int, string>(44, "B"));
	realAnswer.insert(pair<int, string>(45, "D"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//5
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "B"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "D"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "D"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "B"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "B"));
	realAnswer.insert(pair<int, string>(33, "B"));
	realAnswer.insert(pair<int, string>(34, "C"));
	realAnswer.insert(pair<int, string>(35, "A"));
	realAnswer.insert(pair<int, string>(36, "B"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "C"));
	realAnswer.insert(pair<int, string>(40, "A"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "C"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "B"));
	realAnswer.insert(pair<int, string>(45, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());
}

void compareData5(vector<map<int, string>>& realAnswers){
	map<int, string>realAnswer;

	//1
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "D"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "A"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "D"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "D"));
	realAnswer.insert(pair<int, string>(15, "A"));
	realAnswer.insert(pair<int, string>(16, "C"));
	realAnswer.insert(pair<int, string>(17, "A"));
	realAnswer.insert(pair<int, string>(18, "D"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "A"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "A"));
	realAnswer.insert(pair<int, string>(28, "C"));
	realAnswer.insert(pair<int, string>(29, "A"));
	realAnswer.insert(pair<int, string>(30, "D"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "D"));
	realAnswer.insert(pair<int, string>(34, "C"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "C"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "C"));
	realAnswer.insert(pair<int, string>(40, "C"));
	realAnswer.insert(pair<int, string>(41, "A"));
	realAnswer.insert(pair<int, string>(42, "A"));
	realAnswer.insert(pair<int, string>(43, "A"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "A"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//2
	realAnswer.insert(pair<int, string>(1, "B"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "A"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "B"));
	realAnswer.insert(pair<int, string>(11, "D"));
	realAnswer.insert(pair<int, string>(12, "D"));
	realAnswer.insert(pair<int, string>(13, "A"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "A"));
	realAnswer.insert(pair<int, string>(17, "A"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "D"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "C"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "D"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "C"));
	realAnswer.insert(pair<int, string>(29, "D"));
	realAnswer.insert(pair<int, string>(30, "B"));
	realAnswer.insert(pair<int, string>(31, "D"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "A"));
	realAnswer.insert(pair<int, string>(35, "A"));
	realAnswer.insert(pair<int, string>(36, "C"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "C"));
	realAnswer.insert(pair<int, string>(40, "B"));
	realAnswer.insert(pair<int, string>(41, "D"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "C"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//3
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "A"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "C"));
	realAnswer.insert(pair<int, string>(13, "D"));
	realAnswer.insert(pair<int, string>(14, "A"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "A"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "A"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "A"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "C"));
	realAnswer.insert(pair<int, string>(32, "B"));
	realAnswer.insert(pair<int, string>(33, "C"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "D"));
	realAnswer.insert(pair<int, string>(36, "B"));
	realAnswer.insert(pair<int, string>(37, "D"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "C"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "B"));
	realAnswer.insert(pair<int, string>(43, "D"));
	realAnswer.insert(pair<int, string>(44, "D"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//4
	realAnswer.insert(pair<int, string>(1, "A"));
	realAnswer.insert(pair<int, string>(2, "C"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "A"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "A"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "D"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "A"));
	realAnswer.insert(pair<int, string>(27, "C"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "B"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "B"));
	realAnswer.insert(pair<int, string>(33, "D"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "D"));
	realAnswer.insert(pair<int, string>(36, "A"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "B"));
	realAnswer.insert(pair<int, string>(40, "C"));
	realAnswer.insert(pair<int, string>(41, "D"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "C"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//5
	realAnswer.insert(pair<int, string>(1, "D"));
	realAnswer.insert(pair<int, string>(2, "C"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "A"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "D"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "D"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "A"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "B"));
	realAnswer.insert(pair<int, string>(33, "D"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "D"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "B"));
	realAnswer.insert(pair<int, string>(40, "C"));
	realAnswer.insert(pair<int, string>(41, "D"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "C"));
	realAnswer.insert(pair<int, string>(45, "D"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());
}

void compareData6(vector<map<int, string>>& realAnswers){
	map<int, string>realAnswer;

	//1
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "D"));
	realAnswer.insert(pair<int, string>(3, "A"));
	realAnswer.insert(pair<int, string>(4, "C"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "C"));
	realAnswer.insert(pair<int, string>(9, "C"));
	realAnswer.insert(pair<int, string>(10, "B"));
	realAnswer.insert(pair<int, string>(11, "A"));
	realAnswer.insert(pair<int, string>(12, "D"));
	realAnswer.insert(pair<int, string>(13, "D"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "C"));
	realAnswer.insert(pair<int, string>(17, "A"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "D"));
	realAnswer.insert(pair<int, string>(20, "B"));
	realAnswer.insert(pair<int, string>(21, "D"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "C"));
	realAnswer.insert(pair<int, string>(24, "A"));
	realAnswer.insert(pair<int, string>(25, "C"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "A"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "D"));
	realAnswer.insert(pair<int, string>(34, "C"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "B"));
	realAnswer.insert(pair<int, string>(37, "D"));
	realAnswer.insert(pair<int, string>(38, "A"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "B"));
	realAnswer.insert(pair<int, string>(41, "C"));
	realAnswer.insert(pair<int, string>(42, "A"));
	realAnswer.insert(pair<int, string>(43, "D"));
	realAnswer.insert(pair<int, string>(44, "A"));
	realAnswer.insert(pair<int, string>(45, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//2
	realAnswer.insert(pair<int, string>(1, "B"));
	realAnswer.insert(pair<int, string>(2, "A"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "A"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "A"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "C"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "D"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "A"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "A"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "D"));
	realAnswer.insert(pair<int, string>(34, "C"));
	realAnswer.insert(pair<int, string>(35, "D"));
	realAnswer.insert(pair<int, string>(36, "A"));
	realAnswer.insert(pair<int, string>(37, "D"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "D"));
	realAnswer.insert(pair<int, string>(40, "A"));
	realAnswer.insert(pair<int, string>(41, "C"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "C"));
	realAnswer.insert(pair<int, string>(44, "B"));
	realAnswer.insert(pair<int, string>(45, "C"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//3
	realAnswer.insert(pair<int, string>(1, "B"));
	realAnswer.insert(pair<int, string>(2, "B"));
	realAnswer.insert(pair<int, string>(3, "B"));
	realAnswer.insert(pair<int, string>(4, "B"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "B"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "B"));
	realAnswer.insert(pair<int, string>(11, "B"));
	realAnswer.insert(pair<int, string>(12, "B"));
	realAnswer.insert(pair<int, string>(13, "B"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "B"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "B"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "B"));
	realAnswer.insert(pair<int, string>(20, "B"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "B"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "B"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "B"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "B"));
	realAnswer.insert(pair<int, string>(33, "B"));
	realAnswer.insert(pair<int, string>(34, "B"));
	realAnswer.insert(pair<int, string>(35, "B"));
	realAnswer.insert(pair<int, string>(36, "B"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "B"));
	realAnswer.insert(pair<int, string>(40, "B"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "B"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "B"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//4
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "C"));
	realAnswer.insert(pair<int, string>(3, "C"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "A"));
	realAnswer.insert(pair<int, string>(7, "A"));
	realAnswer.insert(pair<int, string>(8, "D"));
	realAnswer.insert(pair<int, string>(9, "A"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "A"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "C"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "C"));
	realAnswer.insert(pair<int, string>(18, "D"));
	realAnswer.insert(pair<int, string>(19, "C"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "B"));
	realAnswer.insert(pair<int, string>(22, "B"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "A"));
	realAnswer.insert(pair<int, string>(25, "B"));
	realAnswer.insert(pair<int, string>(26, "A"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "B"));
	realAnswer.insert(pair<int, string>(30, "C"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "A"));
	realAnswer.insert(pair<int, string>(33, "B"));
	realAnswer.insert(pair<int, string>(34, "A"));
	realAnswer.insert(pair<int, string>(35, "A"));
	realAnswer.insert(pair<int, string>(36, "D"));
	realAnswer.insert(pair<int, string>(37, "C"));
	realAnswer.insert(pair<int, string>(38, "C"));
	realAnswer.insert(pair<int, string>(39, "C"));
	realAnswer.insert(pair<int, string>(40, "D"));
	realAnswer.insert(pair<int, string>(41, "B"));
	realAnswer.insert(pair<int, string>(42, "D"));
	realAnswer.insert(pair<int, string>(43, "B"));
	realAnswer.insert(pair<int, string>(44, "C"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());

	//5
	realAnswer.insert(pair<int, string>(1, "C"));
	realAnswer.insert(pair<int, string>(2, "D"));
	realAnswer.insert(pair<int, string>(3, "A"));
	realAnswer.insert(pair<int, string>(4, "D"));
	realAnswer.insert(pair<int, string>(5, "B"));
	realAnswer.insert(pair<int, string>(6, "C"));
	realAnswer.insert(pair<int, string>(7, "B"));
	realAnswer.insert(pair<int, string>(8, "B"));
	realAnswer.insert(pair<int, string>(9, "B"));
	realAnswer.insert(pair<int, string>(10, "D"));
	realAnswer.insert(pair<int, string>(11, "C"));
	realAnswer.insert(pair<int, string>(12, "A"));
	realAnswer.insert(pair<int, string>(13, "A"));
	realAnswer.insert(pair<int, string>(14, "B"));
	realAnswer.insert(pair<int, string>(15, "B"));
	realAnswer.insert(pair<int, string>(16, "B"));
	realAnswer.insert(pair<int, string>(17, "A"));
	realAnswer.insert(pair<int, string>(18, "B"));
	realAnswer.insert(pair<int, string>(19, "A"));
	realAnswer.insert(pair<int, string>(20, "A"));
	realAnswer.insert(pair<int, string>(21, "C"));
	realAnswer.insert(pair<int, string>(22, "D"));
	realAnswer.insert(pair<int, string>(23, "D"));
	realAnswer.insert(pair<int, string>(24, "B"));
	realAnswer.insert(pair<int, string>(25, "A"));
	realAnswer.insert(pair<int, string>(26, "C"));
	realAnswer.insert(pair<int, string>(27, "B"));
	realAnswer.insert(pair<int, string>(28, "B"));
	realAnswer.insert(pair<int, string>(29, "C"));
	realAnswer.insert(pair<int, string>(30, "A"));
	realAnswer.insert(pair<int, string>(31, "B"));
	realAnswer.insert(pair<int, string>(32, "C"));
	realAnswer.insert(pair<int, string>(33, "B"));
	realAnswer.insert(pair<int, string>(34, "D"));
	realAnswer.insert(pair<int, string>(35, "A"));
	realAnswer.insert(pair<int, string>(36, "C"));
	realAnswer.insert(pair<int, string>(37, "B"));
	realAnswer.insert(pair<int, string>(38, "B"));
	realAnswer.insert(pair<int, string>(39, "A"));
	realAnswer.insert(pair<int, string>(40, "C"));
	realAnswer.insert(pair<int, string>(41, "D"));
	realAnswer.insert(pair<int, string>(42, "B"));
	realAnswer.insert(pair<int, string>(43, "C"));
	realAnswer.insert(pair<int, string>(44, "B"));
	realAnswer.insert(pair<int, string>(45, "B"));
	realAnswers.push_back(realAnswer);
	realAnswer.erase(realAnswer.begin(), realAnswer.end());
}
//void compareData6(vector<map<int, string>>& realAnswers){
//	map<int, string>realAnswer;
//
//	//1
//	realAnswer.insert(pair<int, string>(1, "C"));
//	realAnswer.insert(pair<int, string>(2, "D"));
//	realAnswer.insert(pair<int, string>(3, "A"));
//	realAnswer.insert(pair<int, string>(4, "C"));
//	realAnswer.insert(pair<int, string>(5, "B"));
//	realAnswer.insert(pair<int, string>(6, "B"));
//	realAnswer.insert(pair<int, string>(7, "A"));
//	realAnswer.insert(pair<int, string>(8, "C"));
//	realAnswer.insert(pair<int, string>(9, "C"));
//	realAnswer.insert(pair<int, string>(10, "B"));
//	realAnswer.insert(pair<int, string>(11, "A"));
//	realAnswer.insert(pair<int, string>(12, "D"));
//	realAnswer.insert(pair<int, string>(13, "D"));
//	realAnswer.insert(pair<int, string>(14, "B"));
//	realAnswer.insert(pair<int, string>(15, "C"));
//	realAnswer.insert(pair<int, string>(16, "C"));
//	realAnswer.insert(pair<int, string>(17, "A"));
//	realAnswer.insert(pair<int, string>(18, "B"));
//	realAnswer.insert(pair<int, string>(19, "D"));
//	realAnswer.insert(pair<int, string>(20, "B"));
//	realAnswer.insert(pair<int, string>(21, "D"));
//	realAnswer.insert(pair<int, string>(22, "B"));
//	realAnswer.insert(pair<int, string>(23, "C"));
//	realAnswer.insert(pair<int, string>(24, "A"));
//	realAnswer.insert(pair<int, string>(25, "C"));
//	realAnswer.insert(pair<int, string>(26, "C"));
//	realAnswer.insert(pair<int, string>(27, "B"));
//	realAnswer.insert(pair<int, string>(28, "A"));
//	realAnswer.insert(pair<int, string>(29, "B"));
//	realAnswer.insert(pair<int, string>(30, "C"));
//	realAnswer.insert(pair<int, string>(31, "B"));
//	realAnswer.insert(pair<int, string>(32, "C"));
//	realAnswer.insert(pair<int, string>(33, "D"));
//	realAnswer.insert(pair<int, string>(34, "C"));
//	realAnswer.insert(pair<int, string>(35, "B"));
//	realAnswer.insert(pair<int, string>(36, "B"));
//	realAnswer.insert(pair<int, string>(37, "D"));
//	realAnswer.insert(pair<int, string>(38, "A"));
//	realAnswer.insert(pair<int, string>(39, "D"));
//	realAnswer.insert(pair<int, string>(40, "B"));
//	realAnswer.insert(pair<int, string>(41, "C"));
//	realAnswer.insert(pair<int, string>(42, "A"));
//	realAnswer.insert(pair<int, string>(43, "D"));
//	realAnswer.insert(pair<int, string>(44, "A"));
//	realAnswer.insert(pair<int, string>(45, "C"));
//	realAnswers.push_back(realAnswer);
//	realAnswer.erase(realAnswer.begin(), realAnswer.end());
//
//	//2
//	realAnswer.insert(pair<int, string>(1, "B"));
//	realAnswer.insert(pair<int, string>(2, "A"));
//	realAnswer.insert(pair<int, string>(3, "C"));
//	realAnswer.insert(pair<int, string>(4, "D"));
//	realAnswer.insert(pair<int, string>(5, "B"));
//	realAnswer.insert(pair<int, string>(6, "C"));
//	realAnswer.insert(pair<int, string>(7, "A"));
//	realAnswer.insert(pair<int, string>(8, "B"));
//	realAnswer.insert(pair<int, string>(9, "B"));
//	realAnswer.insert(pair<int, string>(10, "A"));
//	realAnswer.insert(pair<int, string>(11, "C"));
//	realAnswer.insert(pair<int, string>(12, "A"));
//	realAnswer.insert(pair<int, string>(13, "B"));
//	realAnswer.insert(pair<int, string>(14, "B"));
//	realAnswer.insert(pair<int, string>(15, "C"));
//	realAnswer.insert(pair<int, string>(16, "A"));
//	realAnswer.insert(pair<int, string>(17, "C"));
//	realAnswer.insert(pair<int, string>(18, "B"));
//	realAnswer.insert(pair<int, string>(19, "C"));
//	realAnswer.insert(pair<int, string>(20, "C"));
//	realAnswer.insert(pair<int, string>(21, "B"));
//	realAnswer.insert(pair<int, string>(22, "D"));
//	realAnswer.insert(pair<int, string>(23, "B"));
//	realAnswer.insert(pair<int, string>(24, "B"));
//	realAnswer.insert(pair<int, string>(25, "A"));
//	realAnswer.insert(pair<int, string>(26, "B"));
//	realAnswer.insert(pair<int, string>(27, "A"));
//	realAnswer.insert(pair<int, string>(28, "B"));
//	realAnswer.insert(pair<int, string>(29, "C"));
//	realAnswer.insert(pair<int, string>(30, "A"));
//	realAnswer.insert(pair<int, string>(31, "B"));
//	realAnswer.insert(pair<int, string>(32, "C"));
//	realAnswer.insert(pair<int, string>(33, "D"));
//	realAnswer.insert(pair<int, string>(34, "C"));
//	realAnswer.insert(pair<int, string>(35, "D"));
//	realAnswer.insert(pair<int, string>(36, "A"));
//	realAnswer.insert(pair<int, string>(37, "D"));
//	realAnswer.insert(pair<int, string>(38, "C"));
//	realAnswer.insert(pair<int, string>(39, "D"));
//	realAnswer.insert(pair<int, string>(40, "A"));
//	realAnswer.insert(pair<int, string>(41, "C"));
//	realAnswer.insert(pair<int, string>(42, "D"));
//	realAnswer.insert(pair<int, string>(43, "C"));
//	realAnswer.insert(pair<int, string>(44, "B"));
//	realAnswer.insert(pair<int, string>(45, "C"));
//	realAnswers.push_back(realAnswer);
//	realAnswer.erase(realAnswer.begin(), realAnswer.end());
//
//	//3
//	realAnswer.insert(pair<int, string>(1, "B"));
//	realAnswer.insert(pair<int, string>(2, "B"));
//	realAnswer.insert(pair<int, string>(3, "B"));
//	realAnswer.insert(pair<int, string>(4, "B"));
//	realAnswer.insert(pair<int, string>(5, "B"));
//	realAnswer.insert(pair<int, string>(6, "B"));
//	realAnswer.insert(pair<int, string>(7, "B"));
//	realAnswer.insert(pair<int, string>(8, "B"));
//	realAnswer.insert(pair<int, string>(9, "B"));
//	realAnswer.insert(pair<int, string>(10, "B"));
//	realAnswer.insert(pair<int, string>(11, "B"));
//	realAnswer.insert(pair<int, string>(12, "B"));
//	realAnswer.insert(pair<int, string>(13, "B"));
//	realAnswer.insert(pair<int, string>(14, "B"));
//	realAnswer.insert(pair<int, string>(15, "B"));
//	realAnswer.insert(pair<int, string>(16, "B"));
//	realAnswer.insert(pair<int, string>(17, "B"));
//	realAnswer.insert(pair<int, string>(18, "B"));
//	realAnswer.insert(pair<int, string>(19, "B"));
//	realAnswer.insert(pair<int, string>(20, "B"));
//	realAnswer.insert(pair<int, string>(21, "B"));
//	realAnswer.insert(pair<int, string>(22, "B"));
//	realAnswer.insert(pair<int, string>(23, "B"));
//	realAnswer.insert(pair<int, string>(24, "B"));
//	realAnswer.insert(pair<int, string>(25, "B"));
//	realAnswer.insert(pair<int, string>(26, "B"));
//	realAnswer.insert(pair<int, string>(27, "B"));
//	realAnswer.insert(pair<int, string>(28, "B"));
//	realAnswer.insert(pair<int, string>(29, "B"));
//	realAnswer.insert(pair<int, string>(30, "B"));
//	realAnswer.insert(pair<int, string>(31, "B"));
//	realAnswer.insert(pair<int, string>(32, "B"));
//	realAnswer.insert(pair<int, string>(33, "B"));
//	realAnswer.insert(pair<int, string>(34, "B"));
//	realAnswer.insert(pair<int, string>(35, "B"));
//	realAnswer.insert(pair<int, string>(36, "B"));
//	realAnswer.insert(pair<int, string>(37, "B"));
//	realAnswer.insert(pair<int, string>(38, "B"));
//	realAnswer.insert(pair<int, string>(39, "B"));
//	realAnswer.insert(pair<int, string>(40, "B"));
//	realAnswer.insert(pair<int, string>(41, "B"));
//	realAnswer.insert(pair<int, string>(42, "B"));
//	realAnswer.insert(pair<int, string>(43, "B"));
//	realAnswer.insert(pair<int, string>(44, "B"));
//	realAnswer.insert(pair<int, string>(45, "B"));
//	realAnswers.push_back(realAnswer);
//	realAnswer.erase(realAnswer.begin(), realAnswer.end());
//
//	//4
//	realAnswer.insert(pair<int, string>(1, "C"));
//	realAnswer.insert(pair<int, string>(2, "C"));
//	realAnswer.insert(pair<int, string>(3, "C"));
//	realAnswer.insert(pair<int, string>(4, "D"));
//	realAnswer.insert(pair<int, string>(5, "B"));
//	realAnswer.insert(pair<int, string>(6, "A"));
//	realAnswer.insert(pair<int, string>(7, "A"));
//	realAnswer.insert(pair<int, string>(8, "D"));
//	realAnswer.insert(pair<int, string>(9, "A"));
//	realAnswer.insert(pair<int, string>(10, "D"));
//	realAnswer.insert(pair<int, string>(11, "C"));
//	realAnswer.insert(pair<int, string>(12, "A"));
//	realAnswer.insert(pair<int, string>(13, "A"));
//	realAnswer.insert(pair<int, string>(14, "B"));
//	realAnswer.insert(pair<int, string>(15, "C"));
//	realAnswer.insert(pair<int, string>(16, "B"));
//	realAnswer.insert(pair<int, string>(17, "C"));
//	realAnswer.insert(pair<int, string>(18, "D"));
//	realAnswer.insert(pair<int, string>(19, "C"));
//	realAnswer.insert(pair<int, string>(20, "A"));
//	realAnswer.insert(pair<int, string>(21, "B"));
//	realAnswer.insert(pair<int, string>(22, "B"));
//	realAnswer.insert(pair<int, string>(23, "D"));
//	realAnswer.insert(pair<int, string>(24, "A"));
//	realAnswer.insert(pair<int, string>(25, "B"));
//	realAnswer.insert(pair<int, string>(26, "A"));
//	realAnswer.insert(pair<int, string>(27, "B"));
//	realAnswer.insert(pair<int, string>(28, "B"));
//	realAnswer.insert(pair<int, string>(29, "B"));
//	realAnswer.insert(pair<int, string>(30, "C"));
//	realAnswer.insert(pair<int, string>(31, "B"));
//	realAnswer.insert(pair<int, string>(32, "A"));
//	realAnswer.insert(pair<int, string>(33, "B"));
//	realAnswer.insert(pair<int, string>(34, "A"));
//	realAnswer.insert(pair<int, string>(35, "A"));
//	realAnswer.insert(pair<int, string>(36, "D"));
//	realAnswer.insert(pair<int, string>(37, "C"));
//	realAnswer.insert(pair<int, string>(38, "C"));
//	realAnswer.insert(pair<int, string>(39, "C"));
//	realAnswer.insert(pair<int, string>(40, "D"));
//	realAnswer.insert(pair<int, string>(41, "B"));
//	realAnswer.insert(pair<int, string>(42, "D"));
//	realAnswer.insert(pair<int, string>(43, "B"));
//	realAnswer.insert(pair<int, string>(44, "C"));
//	realAnswer.insert(pair<int, string>(45, "B"));
//	realAnswers.push_back(realAnswer);
//	realAnswer.erase(realAnswer.begin(), realAnswer.end());
//
//	//5
//	realAnswer.insert(pair<int, string>(1, "C"));
//	realAnswer.insert(pair<int, string>(2, "D"));
//	realAnswer.insert(pair<int, string>(3, "A"));
//	realAnswer.insert(pair<int, string>(4, "D"));
//	realAnswer.insert(pair<int, string>(5, "B"));
//	realAnswer.insert(pair<int, string>(6, "C"));
//	realAnswer.insert(pair<int, string>(7, "B"));
//	realAnswer.insert(pair<int, string>(8, "B"));
//	realAnswer.insert(pair<int, string>(9, "B"));
//	realAnswer.insert(pair<int, string>(10, "D"));
//	realAnswer.insert(pair<int, string>(11, "C"));
//	realAnswer.insert(pair<int, string>(12, "A"));
//	realAnswer.insert(pair<int, string>(13, "A"));
//	realAnswer.insert(pair<int, string>(14, "B"));
//	realAnswer.insert(pair<int, string>(15, "B"));
//	realAnswer.insert(pair<int, string>(16, "B"));
//	realAnswer.insert(pair<int, string>(17, "A"));
//	realAnswer.insert(pair<int, string>(18, "B"));
//	realAnswer.insert(pair<int, string>(19, "A"));
//	realAnswer.insert(pair<int, string>(20, "A"));
//	realAnswer.insert(pair<int, string>(21, "C"));
//	realAnswer.insert(pair<int, string>(22, "D"));
//	realAnswer.insert(pair<int, string>(23, "D"));
//	realAnswer.insert(pair<int, string>(24, "B"));
//	realAnswer.insert(pair<int, string>(25, "A"));
//	realAnswer.insert(pair<int, string>(26, "C"));
//	realAnswer.insert(pair<int, string>(27, "B"));
//	realAnswer.insert(pair<int, string>(28, "B"));
//	realAnswer.insert(pair<int, string>(29, "C"));
//	realAnswer.insert(pair<int, string>(30, "A"));
//	realAnswer.insert(pair<int, string>(31, "B"));
//	realAnswer.insert(pair<int, string>(32, "C"));
//	realAnswer.insert(pair<int, string>(33, "B"));
//	realAnswer.insert(pair<int, string>(34, "D"));
//	realAnswer.insert(pair<int, string>(35, "A"));
//	realAnswer.insert(pair<int, string>(36, "C"));
//	realAnswer.insert(pair<int, string>(37, "B"));
//	realAnswer.insert(pair<int, string>(38, "B"));
//	realAnswer.insert(pair<int, string>(39, "A"));
//	realAnswer.insert(pair<int, string>(40, "C"));
//	realAnswer.insert(pair<int, string>(41, "D"));
//	realAnswer.insert(pair<int, string>(42, "B"));
//	realAnswer.insert(pair<int, string>(43, "C"));
//	realAnswer.insert(pair<int, string>(44, "B"));
//	realAnswer.insert(pair<int, string>(45, "B"));
//	realAnswers.push_back(realAnswer);
//	realAnswer.erase(realAnswer.begin(), realAnswer.end());
//}
cv::Point FindPoints(cv::Point p1, cv::Point p2, cv::Point p3){
	cv::Point res;
	res.x = p2.x - p1.x + p3.x;
	res.y = p2.y - p1.y + p3.y;
	return res;
}
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}
struct comp{
	bool operator()(string a, string b){
		vector<string>a1, b1;
		SplitString(a, a1,"_");
		SplitString(b, b1, "_");
		string tmp1 = a1[0];
		int x1 = atoi(tmp1.c_str());
		string tmp2 = b1[0];
		int x2 = atoi(tmp2.c_str());
		return x1<x2;
	}
}mycomp;

int main()
{
	string dir_path, tmp;
	while (cin >> tmp)
	{
		//cin >> tmp;
		dir_path = tmp + '\\';
		Directory dir;
		string extenttype = "*.jpg";
		double sum = 0;
		vector<string> fileNames = dir.GetListFiles(dir_path, extenttype, false);
		//将文件名排序
		std::sort(fileNames.begin(), fileNames.end(), mycomp);
		/*****************case: 1***********************/
		if (tmp == "1"){
			vector<map<int, string>> realAnswers;
			compareData(realAnswers);
			double sum_correct = 0.0;
			//cv::Mat tmp = cv::imread("1\\tmp.jpg");
			for (int i = 0; i < fileNames.size(); i++)
			{
				//get image name  
				int num = i;
				string fileName = fileNames[i];
				string fileFullName = dir_path + fileName;
				cv::Mat img = cv::imread(fileFullName);
				namedWindow("srcImage1", CV_WINDOW_NORMAL);
				imshow("srcImage1", img);
				Mat srcImage2, srcImage3, srcImage4, srcImage5, inputMat, outputMat, tmpInputMat;

				//图片变成灰度图片  
				cvtColor(img, srcImage2, CV_BGR2GRAY);
				/*****************debug***********************/
				// 滤波 去噪声
				//cv::blur(srcImage2, inputMat, cv::Size(3, 3));
				// 二值化
				cv::Mat binaryMat;
				//cv::threshold(inputMat, binaryMat, 140, 255, cv::THRESH_BINARY);
				/**********************************/
				/*************校正**************/
				std::vector<cv::Point> filtPoints; // 存放计算的焦点

				//1021
				filtPoints.push_back(Point(133, 490));
				filtPoints.push_back(Point(1031, 490));
				filtPoints.push_back(Point(133, 740));
				filtPoints.push_back(Point(1031, 740));

				// 构造变换矩阵
				cv::Point2f src_vertices[4];
				src_vertices[0] = filtPoints[0];
				src_vertices[1] = filtPoints[1];
				src_vertices[2] = filtPoints[2];
				src_vertices[3] = filtPoints[3];

				cv::Point2f dst_vertices[4];
				dst_vertices[0] = cv::Point(0, 0);
				dst_vertices[1] = cv::Point(srcImage2.rows, 0);
				dst_vertices[2] = cv::Point(0, srcImage2.cols);
				dst_vertices[3] = cv::Point(srcImage2.rows, srcImage2.cols);

				// 透视变换
				cv::Mat transform = cv::getPerspectiveTransform(src_vertices, dst_vertices);
				cv::warpPerspective(srcImage2, inputMat, transform, cv::Size(srcImage2.rows, srcImage2.cols));
				/*namedWindow("inputMat", CV_WINDOW_NORMAL);
				imshow("inputMat", inputMat);*/

			/*	imwrite("testbak.jpg", inputMat);
				waitKey(0);*/
				/*************校正**************/

				cv::threshold(inputMat, binaryMat, 135, 255, cv::THRESH_BINARY);
				//确定腐蚀和膨胀核的大小
				Mat element = getStructuringElement(MORPH_RECT, Size(4, 4));
				//腐蚀操作
				erode(binaryMat, srcImage3, element);
				//膨胀操作
				dilate(srcImage3, srcImage4, element);
				//save image
			/*	namedWindow("srcImage4", CV_WINDOW_NORMAL);
				imshow("srcImage4", srcImage4);*/
				/*imwrite("testbak.jpg", srcImage4);
				waitKey(0);*/
				/**********************************/
				// 设置ROI, 使用容器记录ROI
				std::vector<cv::Rect> ROIRect;
				Mat writeMat = srcImage4.clone();
				//Mat writeMat = binaryMat.clone();
				int leading = 39, top = 29, margin_col = 42, margin_row = 60, width = 325, height = 389, row = 2, col = 4;
//				int leading = 153, top = 490, margin_col = 30, margin_row = 60, width = 197, height = 100, row = 2, col = 4;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						if (i == 1){
							height = 273;
							margin_row = 499;
						}
						if (j >= 2){
							margin_col = 52;
						}
						cv::Rect rect = cv::Rect(j * (width + margin_col) + leading, i * (height + margin_row + 0.7) + top, width, height);
						ROIRect.push_back(rect);
						cv::rectangle(writeMat, rect, cv::Scalar(0, 0, 255), 1);
						/*namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/
					}
				}

				// 遍历ROI，设置并记录每道题的ROI
				std::vector<cv::Rect> ROIItemRect;
				int rows = 5;
				int RectNumbers = 0;

				for (int i = 0; i < ROIRect.size(); i++) {
					cv::Rect rect = ROIRect[i];
					int height = 0;
					height = rect.height / 5;
					if (i >3){
						rows = 3;
						height = rect.height / 3;
					}
					for (int k = 0; k < rows; k++) {
						if (RectNumbers == 30){
							break;
						}
						cv::Rect itemRect = cv::Rect(rect.x, rect.y + height * k, rect.width, height);
						ROIItemRect.push_back(itemRect);
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255), 1);
						RectNumbers++;
					}
				}
				//
				// 二值化 灰度图
				//cv::Mat binaryMat;
				//cv::threshold(inputMat, binaryMat, 100, 255, cv::THRESH_BINARY);


				//对纠偏后的二值化图像，按照上述计算的每道题的 ROI，按照选项横向均等划分为 5 个区域，
				//对应答题卡中的 ABCDE 五个选项，分别对每道题的 ROI 的 5 个区域的像素进行色值统计，统计出色值等于 0 的像素点个数，
				//个数超过该选项总像素点的 25% 时即为有效作答，并且 log 出当前的题号和选项值。：
				//count correct choice
				double correct = 0;
				for (int i = 0; i < ROIItemRect.size(); i++) {  // 遍历每道题
					string res;
					cv::Rect rect = ROIItemRect[i];
					// 分割选项
					int width = rect.width / 6;
					int MAX = 0;
					int m = -1;
					int flag = 0;
					for (int k = 0; k < 6; k++) {
						cv::Rect itemRect = cv::Rect(rect.x + width * k, rect.y, width, rect.height);
						cv::Mat roiMat = writeMat(itemRect);   // 截取ROI
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255), 1);
					/*	namedWindow("writeMat", CV_WINDOW_NORMAL);
						imshow("writeMat", writeMat);
						waitKey(0);*/
						int count = 0;  // 统计色值
						for (int x = 0; x < roiMat.rows; x++) {
							for (int y = 0; y < roiMat.cols; y++) {
								if (roiMat.at<uchar>(x, y) == 0) {
									count++;
								}
							}
						}
						//printf("i= %d,count=%d,th= %f\n", i + 1, count, roiMat.rows * roiMat.cols * 0.25-20);
						//printf("count= %d\n", count);
						if (MAX<count&&count>100){
							MAX = count;
							m = k;
						}
						// 超过 25% 算作有效答案0.3
						if (count > roiMat.rows * roiMat.cols * 0.25-20) {
							flag = 1;
							switch (k) {
							case 0:
								printf("第 %d 题：A \n", i + 1);
								res += 'A';
								break;
							case 1:
								printf("第 %d 题：B \n", i + 1);
								res += 'B';
								break;
							case 2:
								printf("第 %d 题：C \n", i + 1);
								res += 'C';
								break;
							case 3:
								printf("第 %d 题：D \n", i + 1);
								res += 'D';
								break;
							case 4:
								printf("第 %d 题：E \n", i + 1);
								res += 'E';
								break;
							case 5:
								printf("第 %d 题：F \n", i + 1);
								res += 'F';
								break;
							default:
								break;
							}
							continue;
						}
					}
					if (flag == 0){
						switch (m) {
						case -1:
							printf("第 %d 题： \n", i + 1);
							res += ' ';
							break;
						case 0:
							printf("第 %d 题：A \n", i + 1);
							res += 'A';
							break;
						case 1:
							printf("第 %d 题：B \n", i + 1);
							res += 'B';
							break;
						case 2:
							printf("第 %d 题：C \n", i + 1);
							res += 'C';
							break;
						case 3:
							printf("第 %d 题：D \n", i + 1);
							res += 'D';
							break;
						case 4:
							printf("第 %d 题：E \n", i + 1);
							res += 'E';
							break;
						case 5:
							printf("第 %d 题：F \n", i + 1);
							res += 'F';
							break;
						default:
							break;
						}
					}
					/*cout << "res:" << res << endl;
					cout << "realAnswers:" << realAnswers[num][i + 1] << endl;
					cout << "correct:" << correct << endl;*/
					if (res == realAnswers[num][i + 1]){
						correct++;
					}
					//waitKey(0);
				}
				sum_correct += correct;
				printf("acc=%.4f\n", correct / 30.0);
				waitKey(0);
			}
			printf("totoal_acc=%.4f\n", sum_correct / (fileNames.size() * 30));
		}
		/*****************case: 2***********************/
		if (tmp == "2"){
			vector<map<int, string>> realAnswers;
			compareData2(realAnswers);
			double sum_correct = 0;
			for (int i = 0; i < fileNames.size(); i++)
			{
				//get image name  
				int num = i;
				string fileName = fileNames[i];
				string fileFullName = dir_path + fileName;
				cv::Mat img = cv::imread(fileFullName);
				Mat srcImage1 = img;
				namedWindow("srcImage1", CV_WINDOW_NORMAL);
				imshow("srcImage1", srcImage1);
				Mat srcImage2, srcImage3, srcImage4, srcImage5, inputMat, outputMat;

				//图片变成灰度图片  
				cvtColor(srcImage1, srcImage2, CV_BGR2GRAY);
				/*****************debug***********************/
				// 滤波 去噪声
				cv::blur(srcImage2, inputMat, cv::Size(3, 3));
				// 二值化
				cv::Mat binaryMat;
				cv::threshold(inputMat, binaryMat, 98, 255, cv::THRESH_BINARY);

				// 设置ROI, 使用容器记录ROI
				std::vector<cv::Rect> ROIRect;
				Mat writeMat = binaryMat.clone();

				int leading = 189, top = 659, margin_col = 60, margin_row = 20, width = 133, height = 103, row = 2, col = 5;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						cv::Rect rect = cv::Rect(j * (width + margin_col) + leading, i * (height + margin_row + 0.7) + top, width, height);
						ROIRect.push_back(rect);
						cv::rectangle(writeMat, rect, cv::Scalar(0, 0, 255), 1);
					}
				}

				// 遍历ROI，设置并记录每道题的ROI
				std::vector<cv::Rect> ROIItemRect;
				int rows = 5;
				int RectNumbers = 0;
				for (int i = 0; i < ROIRect.size(); i++) {
					cv::Rect rect = ROIRect[i];
					int height = 0;
					height = rect.height / 5;
					for (int k = 0; k < rows; k++) {
						if (RectNumbers == 45){
							break;
						}
						cv::Rect itemRect = cv::Rect(rect.x, rect.y + height * k, rect.width, height);
						ROIItemRect.push_back(itemRect);
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255), 1);
						RectNumbers++;
					}
				}

				//对纠偏后的二值化图像，按照上述计算的每道题的 ROI，按照选项横向均等划分为 5 个区域，
				//对应答题卡中的 ABCDE 五个选项，分别对每道题的 ROI 的 5 个区域的像素进行色值统计，统计出色值等于 0 的像素点个数，
				//个数超过该选项总像素点的 25% 时即为有效作答，并且 log 出当前的题号和选项值。：
				double correct = 0;
				for (int i = 0; i < ROIItemRect.size(); i++) {  // 遍历每道题
					cv::Rect rect = ROIItemRect[i];
					string res;
					// 分割选项
					int MAX = 0;
					int m = -1;
					int flag = 0;
					int width = rect.width / 4;
					for (int k = 0; k < 4; k++) {
						cv::Rect itemRect = cv::Rect(rect.x + width * k, rect.y, width, rect.height);
						cv::Mat roiMat = writeMat(itemRect);   // 截取ROI
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255, 1));
						/*	namedWindow("output", CV_WINDOW_NORMAL);
							imshow("output", writeMat);
							waitKey(0);*/
						int count = 0;  // 统计色值
						for (int x = 0; x < roiMat.rows; x++) {
							for (int y = 0; y < roiMat.cols; y++) {
								if (roiMat.at<uchar>(x, y) == 0) {
									count++;
								}
							}
						}
						if (MAX<count&&count>100){
							MAX = count;
							m = k;
						}
						// 超过 25% 算作有效答案
						if (count > roiMat.rows * roiMat.cols * 0.22) {
							flag = 1;
							switch (k) {
							case 0:
								printf("第 %d 题：A \n", i + 1);
								res += 'A';
								break;
							case 1:
								printf("第 %d 题：B \n", i + 1);
								res += 'B';
								break;
							case 2:
								printf("第 %d 题：C \n", i + 1);
								res += 'C';
								break;
							case 3:
								printf("第 %d 题：D \n", i + 1);
								res += 'D';
								break;
							default:
								break;
							}
							continue;
						}
					}
					if (flag == 0){
						switch (m) {
						case -1:
							printf("第 %d 题：  \n", i + 1);
							res += ' ';
							break;
						case 0:
							printf("第 %d 题：A \n", i + 1);
							res += 'A';
							break;
						case 1:
							printf("第 %d 题：B \n", i + 1);
							res += 'B';
							break;
						case 2:
							printf("第 %d 题：C \n", i + 1);
							res += 'C';
							break;
						case 3:
							printf("第 %d 题：D \n", i + 1);
							res += 'D';
							break;
						default:
							break;
						}
					}
					//cout << "res:" << res << endl;
					//cout << "realAnswers:" << realAnswers[num][i + 1] << endl;
					//cout << "correct:" << correct << endl;
					if (res == realAnswers[num][i + 1]){
						correct++;
					}
				}
				//cout << correct << endl;
				sum_correct += correct;
				printf("acc=%.4f\n", correct / 45.0);
				waitKey(0);
			}
			printf("totoal_acc=%.4f\n", sum_correct / (fileNames.size() * 45));
		}
		/*****************case: 3***********************/
		if (tmp == "3"){
			vector<map<int, string>> realAnswers;
			compareData3(realAnswers);
			double sum_correct = 0;
			for (int i = 0; i < fileNames.size(); i++)
			{
				//get image name  
				int num = i;
				string fileName = fileNames[i];
				string fileFullName = dir_path + fileName;
				cv::Mat img = cv::imread(fileFullName);
				Mat srcImage1 = img;
				namedWindow("srcImage1", CV_WINDOW_NORMAL);
				imshow("srcImage1", srcImage1);
				Mat srcImage2, srcImage3, srcImage4, srcImage5, inputMat, outputMat;

				//图片变成灰度图片  
				cvtColor(srcImage1, srcImage2, CV_BGR2GRAY);
				/*****************debug***********************/
				// 滤波 去噪声
				//cv::blur(srcImage2, inputMat, cv::Size(3, 3));

				// 二值化
				cv::Mat binaryMat;
				//cv::threshold(inputMat, binaryMat, 135, 255, cv::THRESH_BINARY);
				/**********************************/
				/*************校正**************/
				std::vector<cv::Point> filtPoints; // 存放计算的焦点

				//1021
				filtPoints.push_back(Point(103,665));
				filtPoints.push_back(Point(1051, 665));
				filtPoints.push_back(Point(103, 1425));
				filtPoints.push_back(Point(1051, 1425));

				// 构造变换矩阵
				cv::Point2f src_vertices[4];
				src_vertices[0] = filtPoints[0];
				src_vertices[1] = filtPoints[1];
				src_vertices[2] = filtPoints[2];
				src_vertices[3] = filtPoints[3];

				cv::Point2f dst_vertices[4];
				dst_vertices[0] = cv::Point(0, 0);
				dst_vertices[1] = cv::Point(srcImage2.rows, 0);
				dst_vertices[2] = cv::Point(0, srcImage2.cols);
				dst_vertices[3] = cv::Point(srcImage2.rows, srcImage2.cols);

				// 透视变换
				cv::Mat transform = cv::getPerspectiveTransform(src_vertices, dst_vertices);
				cv::warpPerspective(srcImage2, inputMat, transform, cv::Size(srcImage2.rows, srcImage2.cols));
			/*	namedWindow("inputMat", CV_WINDOW_NORMAL);
				imshow("inputMat", inputMat);*/
				
				//imwrite("testbak.jpg", inputMat);
				waitKey(0);
				/*************校正**************/

				cv::threshold(inputMat, binaryMat, 135, 255, cv::THRESH_BINARY);
				//确定腐蚀和膨胀核的大小
				Mat element = getStructuringElement(MORPH_RECT, Size(4, 4));
				//腐蚀操作
				erode(binaryMat, srcImage3, element);
				//膨胀操作
				dilate(srcImage3, srcImage4, element);
				//save image
				/*namedWindow("srcImage4", CV_WINDOW_NORMAL);
				imshow("srcImage4", srcImage4);
				imwrite("testbak.jpg", srcImage4);
				waitKey(0);*/
				/**********************************/
				// 设置ROI, 使用容器记录ROI
				std::vector<cv::Rect> ROIRect;
				//Mat writeMat = srcImage4.clone();
				Mat writeMat = binaryMat.clone();
				int RectNumbers = 0;
				//88
				int leading = 20, top = 13, margin_col = 83, margin_row = 34, width = 170, height = 149, row = 6, col = 6;
				//int leading = 105, top = 676, margin_col = 38, margin_row = 22, width = 123, height = 102, row = 6, col = 6;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						if (RectNumbers == 33){
							break;
						}
						if (RectNumbers >= 30){
							margin_col = 84;
						}
						cv::Rect rect = cv::Rect(i * (width + margin_col) + leading, j * (height + margin_row) + top, width, height);
						ROIRect.push_back(rect);
						cv::rectangle(writeMat, rect, cv::Scalar(0, 0, 255), 1);
						RectNumbers++;
					/*	namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/

					}
				}

				// 遍历ROI，设置并记录每道题的ROI
				std::vector<cv::Rect> ROIItemRect;
				int rows = 5;
				for (int i = 0; i < ROIRect.size(); i++) {
					cv::Rect rect = ROIRect[i];
					int height = 0;
					height = rect.height / 5;
					for (int k = 0; k < rows; k++) {
						cv::Rect itemRect = cv::Rect(rect.x, rect.y + height*k, rect.width, height);
						ROIItemRect.push_back(itemRect);
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255), 1);
					}
				}

				//对纠偏后的二值化图像，按照上述计算的每道题的 ROI，按照选项横向均等划分为 5 个区域，
				//对应答题卡中的 ABCDE 五个选项，分别对每道题的 ROI 的 5 个区域的像素进行色值统计，统计出色值等于 0 的像素点个数，
				//个数超过该选项总像素点的 25% 时即为有效作答，并且 log 出当前的题号和选项值。：
				double correct = 0;
				for (int i = 0; i < ROIItemRect.size(); i++) {  // 遍历每道题
					cv::Rect rect = ROIItemRect[i];
					string res;
					int MAX = 0;
					int m = -1;
					int flag = 0;
					// 分割选项
					int width = rect.width / 4;
					for (int k = 0; k < 4; k++) {
						cv::Rect itemRect = cv::Rect(rect.x + width * k, rect.y, width, rect.height);
						cv::Mat roiMat = writeMat(itemRect);   // 截取ROI
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255, 1));
						/*namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/
						int count = 0;  // 统计色值
						for (int x = 0; x < roiMat.rows; x++) {
							for (int y = 0; y < roiMat.cols; y++) {
								if (roiMat.at<uchar>(x, y) == 0) {
									count++;
								}
							}
						}
						if (MAX<count&&count>100){
							MAX = count;
							m = k;
						}
						//printf("i= %d,count=%d,th= %f\n", i + 1, count, roiMat.rows * roiMat.cols * 0.25);
						// 超过 25% 算作有效答案
						if (count > roiMat.rows * roiMat.cols * 0.25) {
							flag = 1;
							switch (k) {
							case 0:
								printf("第 %d 题：A \n", i + 1);
								res += 'A';
								break;
							case 1:
								printf("第 %d 题：B \n", i + 1);
								res += 'B';
								break;
							case 2:
								printf("第 %d 题：C \n", i + 1);
								res += 'C';
								break;
							case 3:
								printf("第 %d 题：D \n", i + 1);
								res += 'D';
								break;
							default:
								break;
							}
							continue;
						}
						/*else if ((i >= 135)&&(count>120)){
							flag = 1;
							switch (k) {
							case 0:
							printf("第 %d 题：A \n", i + 1);
							res += 'A';
							break;
							case 1:
							printf("第 %d 题：B \n", i + 1);
							res += 'B';
							break;
							case 2:
							printf("第 %d 题：C \n", i + 1);
							res += 'C';
							break;
							case 3:
							printf("第 %d 题：D \n", i + 1);
							res += 'D';
							break;
							default:
							break;
							}
							continue;
							}*/
					}
					if (flag == 0){
						switch (m) {
						case -1:
							printf("第 %d 题：  \n", i + 1);
							res += ' ';
							break;
						case 0:
							printf("第 %d 题：A \n", i + 1);
							res += 'A';
							break;
						case 1:
							printf("第 %d 题：B \n", i + 1);
							res += 'B';
							break;
						case 2:
							printf("第 %d 题：C \n", i + 1);
							res += 'C';
							break;
						case 3:
							printf("第 %d 题：D \n", i + 1);
							res += 'D';
							break;
						default:
							break;
						}
					}
					cout << "res:" << res << endl;
					cout << "realAnswers:" << realAnswers[num][i + 1] << endl;
					cout << "correct:" << correct << endl;
					if (res == realAnswers[num][i + 1]){
						correct++;
					}
				}
				sum_correct += correct;
				printf("acc=%.4f\n", correct / 165.0);
				waitKey(0);
			}
			printf("totoal_acc=%.4f\n", sum_correct / (fileNames.size() * 165));
		}
		/************************case:4***********************/
		if (tmp == "4"){
			vector<map<int, string>> realAnswers;
			compareData4(realAnswers);
			double sum_correct = 0;
			for (int i = 0; i < fileNames.size(); i++)
			{
				//get image name  
				int num = i;
				string fileName = fileNames[i];
				string fileFullName = dir_path + fileName;
				cv::Mat img = cv::imread(fileFullName);
				Mat srcImage1 = img;
				namedWindow("srcImage1", CV_WINDOW_NORMAL);
				imshow("srcImage1", srcImage1);
				Mat srcImage2, srcImage3, srcImage4, srcImage5, inputMat, outputMat;

				//图片变成灰度图片  
				cvtColor(srcImage1, srcImage2, CV_BGR2GRAY);
				/*****************debug***********************/
				// 滤波 去噪声
				cv::blur(srcImage2, inputMat, cv::Size(3, 3));
				// 二值化
				cv::Mat binaryMat;
				cv::threshold(inputMat, binaryMat, 98, 255, cv::THRESH_BINARY);
				/*namedWindow("binary", CV_WINDOW_NORMAL);
				imshow("binary", binaryMat);*/
				// 设置ROI, 使用容器记录ROI
				std::vector<cv::Rect> ROIRect;
				Mat writeMat = binaryMat.clone();
				int leading = 155, top = 675, margin_col = 35, margin_row = 44, width = 159, height = 86, row = 2, col = 5;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						cv::Rect rect = cv::Rect(j * (width + margin_col) + leading, i * (height + margin_row + 0.7) + top, width, height);
						ROIRect.push_back(rect);
						cv::rectangle(writeMat, rect, cv::Scalar(0, 0, 255), 1);
						//namedWindow("output", CV_WINDOW_NORMAL);
						//imshow("output", writeMat);
						//waitKey(0);
					}
				}

				// 遍历ROI，设置并记录每道题的ROI
				std::vector<cv::Rect> ROIItemRect;
				int rows = 5;
				int RectNumbers = 0;
				for (int i = 0; i < ROIRect.size(); i++) {
					cv::Rect rect = ROIRect[i];
					int width = 0;
					width = rect.width / 5;
					for (int k = 0; k < rows; k++) {
						if (RectNumbers == 45){
							break;
						}
						cv::Rect itemRect = cv::Rect(rect.x + width*k, rect.y, width, rect.height);
						ROIItemRect.push_back(itemRect);
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255), 1);
						RectNumbers++;
						//namedWindow("output", CV_WINDOW_NORMAL);
						//imshow("output", writeMat);
						//waitKey(0);
					}
				}

				//对纠偏后的二值化图像，按照上述计算的每道题的 ROI，按照选项横向均等划分为 5 个区域，
				//对应答题卡中的 ABCDE 五个选项，分别对每道题的 ROI 的 5 个区域的像素进行色值统计，统计出色值等于 0 的像素点个数，
				//个数超过该选项总像素点的 25% 时即为有效作答，并且 log 出当前的题号和选项值。：
				double correct = 0;
				for (int i = 0; i < ROIItemRect.size(); i++) {  // 遍历每道题
					string res;
					cv::Rect rect = ROIItemRect[i];
					int MAX = 0;
					int m = -1;
					int flag = 0;
					// 分割选项
					int height = rect.height / 4;
					for (int k = 0; k < 4; k++) {
						cv::Rect itemRect = cv::Rect(rect.x, rect.y + height * k, rect.width, height);
						cv::Mat roiMat = writeMat(itemRect);   // 截取ROI
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255, 1));
						/*namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/
						int count = 0;  // 统计色值
						for (int x = 0; x < roiMat.rows; x++) {
							for (int y = 0; y < roiMat.cols; y++) {

								if (roiMat.at<uchar>(x, y) == 0) {
									count++;
								}
							}
						}
						if (MAX<count&&count>100){
							MAX = count;
							m = k;
						}
						// 超过 25% 算作有效答案
						if (count > roiMat.rows * roiMat.cols * 0.22) {
							flag = 1;
							switch (k) {
							case 0:
								printf("第 %d 题：A \n", i + 1);
								res += 'A';
								break;
							case 1:
								printf("第 %d 题：B \n", i + 1);
								res += 'B';
								break;
							case 2:
								printf("第 %d 题：C \n", i + 1);
								res += 'C';
								break;
							case 3:
								printf("第 %d 题：D \n", i + 1);
								res += 'D';
								break;
							default:
								break;
							}
							continue;
						}
					}
					if (flag == 0){
						switch (m) {
						case -1:
							printf("第 %d 题：   \n", i + 1);
							res += ' ';
							break;
						case 0:
							printf("第 %d 题：A \n", i + 1);
							res += 'A';
							break;
						case 1:
							printf("第 %d 题：B \n", i + 1);
							res += 'B';
							break;
						case 2:
							printf("第 %d 题：C \n", i + 1);
							res += 'C';
							break;
						case 3:
							printf("第 %d 题：D \n", i + 1);
							res += 'D';
							break;
						default:
							break;
						}

					}
					//cout << "res:" << res << endl;
					//cout << "realAnswers:" << realAnswers[num][i + 1] << endl;
					//cout << "correct:" << correct << endl;
					if (num < realAnswers.size()){
						if (res == realAnswers[num][i + 1]){
							correct++;
						}
					}
				}
				sum_correct += correct;
				printf("acc=%.4f\n", correct / 45.0);
				waitKey(0);
			}
			printf("totoal_acc=%.4f\n", sum_correct / (fileNames.size() * 45));
		}
		/************************case:5***********************/
		if (tmp == "5"){
			vector<map<int, string>> realAnswers;
			compareData5(realAnswers);
			double sum_correct = 0;
			for (int i = 0; i < fileNames.size(); i++)
			{
				//get image name  
				int num = i;
				string fileName = fileNames[i];
				string fileFullName = dir_path + fileName;
				cv::Mat img = cv::imread(fileFullName);
				Mat srcImage1 = img;
				namedWindow("srcImage1", CV_WINDOW_NORMAL);
				imshow("srcImage1", srcImage1);
				Mat srcImage2, srcImage3, srcImage4, srcImage5, inputMat, outputMat;

				//图片变成灰度图片  
				cvtColor(srcImage1, srcImage2, CV_BGR2GRAY);
				/*****************debug***********************/
				// 滤波 去噪声
				cv::blur(srcImage2, inputMat, cv::Size(3, 3));
				// 二值化
				//cv::threshold(inputMat, outputMat, 100, 255, cv::THRESH_BINARY_INV);
				cv::Mat binaryMat;
				cv::threshold(inputMat, binaryMat, 98, 255, cv::THRESH_BINARY);

				// 设置ROI, 使用容器记录ROI
				std::vector<cv::Rect> ROIRect;
				Mat writeMat = binaryMat.clone();
				int leading = 155, top = 675, margin_col = 35, margin_row = 44, width = 159, height = 86, row = 2, col = 5;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						cv::Rect rect = cv::Rect(j * (width + margin_col) + leading, i * (height + margin_row + 0.7) + top, width, height);
						ROIRect.push_back(rect);
						cv::rectangle(writeMat, rect, cv::Scalar(0, 0, 255), 1);
						//namedWindow("output", CV_WINDOW_NORMAL);
						//imshow("output", writeMat);
						//waitKey(0);
					}
				}

				// 遍历ROI，设置并记录每道题的ROI
				std::vector<cv::Rect> ROIItemRect;
				int rows = 5;
				int RectNumbers = 0;
				for (int i = 0; i < ROIRect.size(); i++) {
					cv::Rect rect = ROIRect[i];
					int width = 0;
					width = rect.width / 5;
					for (int k = 0; k < rows; k++) {
						if (RectNumbers == 45){
							break;
						}
						cv::Rect itemRect = cv::Rect(rect.x + width*k, rect.y, width, rect.height);
						ROIItemRect.push_back(itemRect);
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255), 1);
						RectNumbers++;
						//namedWindow("output", CV_WINDOW_NORMAL);
						//imshow("output", writeMat);
						//waitKey(0);
					}
				}

				//对纠偏后的二值化图像，按照上述计算的每道题的 ROI，按照选项横向均等划分为 5 个区域，
				//对应答题卡中的 ABCDE 五个选项，分别对每道题的 ROI 的 5 个区域的像素进行色值统计，统计出色值等于 0 的像素点个数，
				//个数超过该选项总像素点的 25% 时即为有效作答，并且 log 出当前的题号和选项值。：
				double correct = 0;
				for (int i = 0; i < ROIItemRect.size(); i++) {  // 遍历每道题
					cv::Rect rect = ROIItemRect[i];
					string res;
					int MAX = 0;
					int flag = 0;
					int m = -1;
					// 分割选项
					int height = rect.height / 4;
					for (int k = 0; k < 4; k++) {
						cv::Rect itemRect = cv::Rect(rect.x, rect.y + height * k, rect.width, height);
						cv::Mat roiMat = writeMat(itemRect);   // 截取ROI
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255, 1));
						/*namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/
						int count = 0;  // 统计色值
						for (int x = 0; x < roiMat.rows; x++) {
							for (int y = 0; y < roiMat.cols; y++) {
								if (roiMat.at<uchar>(x, y) == 0) {
									count++;
								}
							}
						}
						if (MAX<count&&count>100){
							MAX = count;
							m = k;
						}
						// 超过 25% 算作有效答案
						if (count > roiMat.rows * roiMat.cols * 0.25) {
							flag = 1;
							switch (k) {
							case 0:
								printf("第 %d 题：A \n", i + 1);
								res += 'A';
								break;
							case 1:
								printf("第 %d 题：B \n", i + 1);
								res += 'B';
								break;
							case 2:
								printf("第 %d 题：C \n", i + 1);
								res += 'C';
								break;
							case 3:
								printf("第 %d 题：D \n", i + 1);
								res += 'D';
								break;
							default:
								break;
							}
							continue;
						}
					}
					if (flag == 0){
						switch (m) {
						case -1:
							printf("第 %d 题：  \n", i + 1);
							res += ' ';
							break;
						case 0:
							printf("第 %d 题：A \n", i + 1);
							res += 'A';
							break;
						case 1:
							printf("第 %d 题：B \n", i + 1);
							res += 'B';
							break;
						case 2:
							printf("第 %d 题：C \n", i + 1);
							res += 'C';
							break;
						case 3:
							printf("第 %d 题：D \n", i + 1);
							res += 'D';
							break;
						default:
							break;
						}
					}
					//cout << "res:" << res << endl;
					//cout << "realAnswers:" << realAnswers[num][i + 1] << endl;
					//cout << "correct:" << correct << endl;
					if (res == realAnswers[num][i + 1]){
						correct++;
					}
				}
				sum_correct += correct;
				printf("acc=%.4f\n", correct / 45.0);
				//Mat out = srcImage2(Rect(100, 490, 950, 100));
				//namedWindow("output", CV_WINDOW_NORMAL);
				//	imshow("output", writeMat);
				waitKey(0);
			}
			printf("totoal_acc=%.4f\n", sum_correct / (fileNames.size() * 45));
		}
		/************************case:6***********************/
		if (tmp == "6"){
			vector<map<int, string>> realAnswers;
			compareData6(realAnswers);
			double sum_correct = 0;
			for (int i = 0; i < fileNames.size(); i++)
			{
				//get image name  
				int num = i;
				string fileName = fileNames[i];
				string fileFullName = dir_path + fileName;
				cv::Mat img = cv::imread(fileFullName);
				Mat srcImage1 = img;
				namedWindow("srcImage1", CV_WINDOW_NORMAL);
				imshow("srcImage1", srcImage1);
				Mat srcImage2, srcImage3, srcImage4, srcImage5, inputMat, outputMat;

				//图片变成灰度图片  
				cvtColor(srcImage1, srcImage2, CV_BGR2GRAY);
				/*****************debug***********************/
				// 滤波 去噪声
				cv::blur(srcImage2, inputMat, cv::Size(3, 3));
				// 二值化
				//cv::threshold(inputMat, outputMat, 100, 255, cv::THRESH_BINARY_INV);
				cv::Mat binaryMat;
				cv::threshold(inputMat, binaryMat, 98, 255, cv::THRESH_BINARY);

				// 设置ROI, 使用容器记录ROI
				std::vector<cv::Rect> ROIRect;
				Mat writeMat = binaryMat.clone();
				int leading = 189, top = 659, margin_col = 60, margin_row = 20, width = 133, height = 103, row = 2, col = 5;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						cv::Rect rect = cv::Rect(j * (width + margin_col) + leading, i * (height + margin_row + 0.7) + top, width, height);
						ROIRect.push_back(rect);
						cv::rectangle(writeMat, rect, cv::Scalar(0, 0, 255), 1);
					}
				}

				// 遍历ROI，设置并记录每道题的ROI
				std::vector<cv::Rect> ROIItemRect;
				int rows = 5;
				int RectNumbers = 0;
				for (int i = 0; i < ROIRect.size(); i++) {
					cv::Rect rect = ROIRect[i];
					int height = 0;
					height = rect.height / 5;
					for (int k = 0; k < rows; k++) {
						if (RectNumbers == 45){
							break;
						}
						cv::Rect itemRect = cv::Rect(rect.x, rect.y + height * k, rect.width, height);
						ROIItemRect.push_back(itemRect);
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255), 1);
						RectNumbers++;
						//namedWindow("output", CV_WINDOW_NORMAL);
						//imshow("output", writeMat);
						//waitKey(0);
					}
				}

				//对纠偏后的二值化图像，按照上述计算的每道题的 ROI，按照选项横向均等划分为 5 个区域，
				//对应答题卡中的 ABCDE 五个选项，分别对每道题的 ROI 的 5 个区域的像素进行色值统计，统计出色值等于 0 的像素点个数，
				//个数超过该选项总像素点的 25% 时即为有效作答，并且 log 出当前的题号和选项值。：
				double correct = 0;
				for (int i = 0; i < ROIItemRect.size(); i++) {  // 遍历每道题
					cv::Rect rect = ROIItemRect[i];
					string res;
					int MAX = 0;
					int flag = 0;
					int m = -1;
					// 分割选项
					int width = rect.width / 4;
					for (int k = 0; k < 4; k++) {
						cv::Rect itemRect = cv::Rect(rect.x + width * k, rect.y, width, rect.height);
						cv::Mat roiMat = writeMat(itemRect);   // 截取ROI

						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255, 1));
						/*namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/
						int count = 0;  // 统计色值
						for (int x = 0; x < roiMat.rows; x++) {
							for (int y = 0; y < roiMat.cols; y++) {

								if (roiMat.at<uchar>(x, y) == 0) {
									count++;
								}
							}
						}
						if (MAX<count&&count>100){
							MAX = count;
							m = k;
						}

						// 超过 25% 算作有效答案
						if (count > roiMat.rows * roiMat.cols * 0.25) {
							flag = 1;
							switch (k) {
							case 0:
								printf("第 %d 题：A \n", i + 1);
								res += 'A';
								break;
							case 1:
								printf("第 %d 题：B \n", i + 1);
								res += 'B';
								break;
							case 2:
								printf("第 %d 题：C \n", i + 1);
								res += 'C';
								break;
							case 3:
								printf("第 %d 题：D \n", i + 1);
								res += 'D';
								break;
							default:
								break;
							}
							continue;
						}
					}
					if (flag == 0){
						switch (m) {
						case -1:
							printf("第 %d 题：  \n", i + 1);
							res += ' ';
							break;
						case 0:
							printf("第 %d 题：A \n", i + 1);
							res += 'A';
							break;
						case 1:
							printf("第 %d 题：B \n", i + 1);
							res += 'B';
							break;
						case 2:
							printf("第 %d 题：C \n", i + 1);
							res += 'C';
							break;
						case 3:
							printf("第 %d 题：D \n", i + 1);
							res += 'D';
							break;
						default:
							break;
						}
					}
					//cout << "res:" << res << endl;
					//cout << "realAnswers:" << realAnswers[num][i + 1] << endl;
					//cout << "correct:" << correct << endl;
					if (num < realAnswers.size()){
						if (res == realAnswers[num][i + 1]){
							correct++;
						}
					}
				}
				sum_correct += correct;
				printf("acc=%.4f\n", correct / 45.0);
				waitKey(0);
			}
			printf("totoal_acc=%.4f\n", sum_correct / (fileNames.size() * 45));
		}
		/*****************case: 7***********************/
		if (tmp == "7"){
			vector<map<int, string>> realAnswers;
			compareData3(realAnswers);
			double sum_correct = 0;
			for (int i = 0; i < fileNames.size(); i++)
			{
				//get image name  
				int num = i;
				string fileName = fileNames[i];
				string fileFullName = dir_path + fileName;
				cv::Mat img = cv::imread(fileFullName);
				Mat srcImage1 = img;
				namedWindow("srcImage1", CV_WINDOW_NORMAL);
				imshow("srcImage1", srcImage1);
				Mat srcImage2, srcImage3, srcImage4, srcImage5, inputMat, outputMat;

				//图片变成灰度图片  
				cvtColor(srcImage1, srcImage2, CV_BGR2GRAY);
				/*****************debug***********************/
				// 滤波 去噪声
				//cv::blur(srcImage2, inputMat, cv::Size(3, 3));

				// 二值化
				cv::Mat binaryMat;
				//cv::threshold(inputMat, binaryMat, 135, 255, cv::THRESH_BINARY);
				/**********************************/
				/********使用傅里叶校正********/
				/******************************/
				Point center(srcImage2.cols / 2, srcImage2.rows / 2);
				//Expand image to an optimal size, for faster processing speed
				//Set widths of borders in four directions
				//If borderType==BORDER_CONSTANT, fill the borders with (0,0,0)
				Mat padded;
				int opWidth = getOptimalDFTSize(srcImage2.rows);
				int opHeight = getOptimalDFTSize(srcImage2.cols);
				copyMakeBorder(srcImage2, padded, 0, opWidth - srcImage2.rows, 0, opHeight - srcImage2.cols, BORDER_CONSTANT, Scalar::all(0));

				Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
				Mat comImg;
				//Merge into a double-channel image
				merge(planes, 2, comImg);

				//Use the same image as input and output,
				//so that the results can fit in Mat well
				dft(comImg, comImg);

				//Compute the magnitude
				//planes[0]=Re(DFT(I)), planes[1]=Im(DFT(I))
				//magnitude=sqrt(Re^2+Im^2)
				split(comImg, planes);
				magnitude(planes[0], planes[1], planes[0]);

				//Switch to logarithmic scale, for better visual results
				//M2=log(1+M1)
				Mat magMat = planes[0];
				magMat += Scalar::all(1);
				log(magMat, magMat);

				//Crop the spectrum
				//Width and height of magMat should be even, so that they can be divided by 2
				//-2 is 11111110 in binary system, operator & make sure width and height are always even
				magMat = magMat(Rect(0, 0, magMat.cols & -2, magMat.rows & -2));

				//Rearrange the quadrants of Fourier image,
				//so that the origin is at the center of image,
				//and move the high frequency to the corners
				int cx = magMat.cols / 2;
				int cy = magMat.rows / 2;

				Mat q0(magMat, Rect(0, 0, cx, cy));
				Mat q1(magMat, Rect(0, cy, cx, cy));
				Mat q2(magMat, Rect(cx, cy, cx, cy));
				Mat q3(magMat, Rect(cx, 0, cx, cy));

				Mat tmp;
				q0.copyTo(tmp);
				q2.copyTo(q0);
				tmp.copyTo(q2);

				q1.copyTo(tmp);
				q3.copyTo(q1);
				tmp.copyTo(q3);

				//Normalize the magnitude to [0,1], then to[0,255]
				normalize(magMat, magMat, 0, 1, CV_MINMAX);
				Mat magImg(magMat.size(), CV_8UC1);
				magMat.convertTo(magImg, CV_8UC1, 255, 0);
				/*namedWindow("magnitude", CV_WINDOW_NORMAL);
				imshow("magnitude", magImg);*/
				//imwrite("imageText_mag.jpg",magImg);

				//Turn into binary image
				threshold(magImg, magImg, GRAY_THRESH, 255, CV_THRESH_BINARY);
				/*namedWindow("mag_binary", CV_WINDOW_NORMAL);
				imshow("mag_binary", magImg);*/
				//imwrite("imageText_bin.jpg",magImg);

				//Find lines with Hough Transformation
				vector<Vec2f> lines;
				float pi180 = (float)CV_PI / 180;
				Mat linImg(magImg.size(), CV_8UC3);
				HoughLines(magImg, lines, 1, pi180, HOUGH_VOTE, 0, 0);
				int numLines = lines.size();
				for (int l = 0; l<numLines; l++)
				{
					float rho = lines[l][0], theta = lines[l][1];
					Point pt1, pt2;
					double a = cos(theta), b = sin(theta);
					double x0 = a*rho, y0 = b*rho;
					pt1.x = cvRound(x0 + 1000 * (-b));
					pt1.y = cvRound(y0 + 1000 * (a));
					pt2.x = cvRound(x0 - 1000 * (-b));
					pt2.y = cvRound(y0 - 1000 * (a));
					line(linImg, pt1, pt2, Scalar(255, 0, 0), 3, 8, 0);
				}
				/*namedWindow("lines", CV_WINDOW_NORMAL);
				imshow("lines", linImg);*/
				//imwrite("imageText_line.jpg",linImg);
				//if (lines.size() == 3)
				/*	for (int l = 0; l<numLines; l++)
				{
					cout << "found  angels:" << endl;
					cout << lines[l][1] * 180 / CV_PI << endl << lines[l][1] * 180 / CV_PI << endl << lines[l][1] * 180 / CV_PI << endl << endl;
				}*/

				//Find the proper angel from the three found angels
				float angel = 0;
				float piThresh = (float)CV_PI / 90;
				float pi2 = CV_PI / 2;
				for (int l = 0; l<numLines; l++)
				{
					float theta = lines[l][1];
					if (abs(theta) < piThresh || abs(theta - pi2) < piThresh)
						continue;
					else{
						angel = theta;
						break;
					}
				}

				//Calculate the rotation angel
				//The image has to be square,
				//so that the rotation angel can be calculate right
				angel = angel<pi2 ? angel : angel - CV_PI;
				if (angel != pi2){
					float angelT = srcImage2.rows*tan(angel) / srcImage2.cols;
					angel = atan(angelT);
				}
				float angelD = angel * 180 / (float)CV_PI;
				//cout << "the rotation angel to be applied:" << endl << angelD << endl << endl;

				//Rotate the image to recover
				Mat rotMat = getRotationMatrix2D(center, angelD, 1.0);
				Mat dstImg = Mat::ones(srcImage2.size(), CV_8UC3);
				warpAffine(srcImage2, dstImg, rotMat, srcImage2.size(), 1, 0, Scalar(255, 255, 255));
				/*namedWindow("result", CV_WINDOW_NORMAL);
				imshow("result", dstImg);*/
				imwrite("imageText_D.jpg",dstImg);
				waitKey(0);
				/**********************************/
				/********使用傅里叶校正********/
				/******************************/


				//cv::threshold(inputMat, binaryMat, 135, 255, cv::THRESH_BINARY);
				cv::threshold(dstImg, binaryMat, 245, 255, cv::THRESH_BINARY);

				//确定腐蚀和膨胀核的大小
				Mat element = getStructuringElement(MORPH_RECT, Size(4, 4));
				//腐蚀操作
				erode(binaryMat, srcImage3, element);
				//膨胀操作
				dilate(srcImage3, srcImage4, element);
				//save image
				/*namedWindow("srcImage4", CV_WINDOW_NORMAL);
				imshow("srcImage4", binaryMat);*/
				imwrite("testbak.jpg", binaryMat);
				//waitKey(0);
				/**********************************/
				// 设置ROI, 使用容器记录ROI
				std::vector<cv::Rect> ROIRect;
				Mat writeMat = srcImage4.clone();
				//Mat writeMat = binaryMat.clone();
				int RectNumbers = 0;
				//answer sheet I
				int leading = 207, top = 707, margin_col = 93, margin_row = 39, width = 150, height = 157, row = 5, col = 4;
				//int leading = 105, top = 676, margin_col = 38, margin_row = 22, width = 123, height = 102, row = 6, col = 6;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						/*if (RectNumbers == 33){
							break;
						}*/
						if (RectNumbers >= 2){
							margin_col = 95;
						}
						cv::Rect rect = cv::Rect(j * (width + margin_col) + leading, i * (height + margin_row) + top, width, height);
						ROIRect.push_back(rect);
						cv::rectangle(writeMat, rect, cv::Scalar(0, 0, 255), 1);
						RectNumbers++;
						/*namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/

					}
				}

				//answer sheet II
				leading = 1359, top = 197, margin_col = 95, margin_row = 46, width = 354, height = 151, row = 5, col = 2;
				//int leading = 105, top = 676, margin_col = 38, margin_row = 22, width = 123, height = 102, row = 6, col = 6;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						/*if (RectNumbers == 33){
						break;
						}*/
						/*if (RectNumbers >= 2){
							margin_col = 95;
						}*/
						cv::Rect rect = cv::Rect(j * (width + margin_col) + leading, i * (height + margin_row) + top, width, height);
						ROIRect.push_back(rect);
						cv::rectangle(writeMat, rect, cv::Scalar(0, 0, 255), 1);
						RectNumbers++;
						/*namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/

					}
				}

				//TrueOrFalse III
				leading = 1357, top = 1276, margin_col = 97, margin_row = 0, width = 66, height = 154, row = 1, col = 6;
				//int leading = 105, top = 676, margin_col = 38, margin_row = 22, width = 123, height = 102, row = 6, col = 6;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						/*if (RectNumbers == 33){
						break;
						}*/
						/*if (RectNumbers >= 2){
						margin_col = 95;
						}*/
						cv::Rect rect = cv::Rect(j * (width + margin_col) + leading, i * (height + margin_row) + top, width, height);
						ROIRect.push_back(rect);
						cv::rectangle(writeMat, rect, cv::Scalar(0, 0, 255), 1);
						RectNumbers++;
						/*namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/

					}
				}
				// 遍历ROI，设置并记录每道题的ROI
				std::vector<cv::Rect> ROIItemRect;
				int rows = 5;
				for (int i = 0; i < ROIRect.size(); i++) {
					cv::Rect rect = ROIRect[i];
					int height = rect.height / rows;
					for (int k = 0; k < rows; k++) {
						cv::Rect itemRect = cv::Rect(rect.x, rect.y + height*k, rect.width, height);
						ROIItemRect.push_back(itemRect);
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255), 1);
						/*namedWindow("output", CV_WINDOW_NORMAL);
						imshow("output", writeMat);
						waitKey(0);*/
					}
				}

				//对纠偏后的二值化图像，按照上述计算的每道题的 ROI，按照选项横向均等划分为 5 个区域，
				//对应答题卡中的 ABCDE 五个选项，分别对每道题的 ROI 的 5 个区域的像素进行色值统计，统计出色值等于 0 的像素点个数，
				//个数超过该选项总像素点的 25% 时即为有效作答，并且 log 出当前的题号和选项值。：
				double correct = 0;
				int choice = 4;
				bool IsJudge = false;
				for (int i = 0; i < ROIItemRect.size(); i++) {  // 遍历每道题
					cv::Rect rect = ROIItemRect[i];
					string res;
					int MAX = 0;
					int m = -1;
					int flag = 0;
					//change choice number
					if (i>99){
						choice = 9;
					}
					if (i > 149){
						IsJudge = true;
						choice = 2;
						m = 2;
					}
					// 分割选项
					int width = rect.width / choice;
					for (int k = 0; k < choice; k++) {
						cv::Rect itemRect = cv::Rect(rect.x + width * k, rect.y, width, rect.height);
						cv::Mat roiMat = writeMat(itemRect);   // 截取ROI
						cv::rectangle(writeMat, itemRect, cv::Scalar(0, 0, 255, 1));
					/*	{
							namedWindow("output", CV_WINDOW_NORMAL);
							imshow("output", writeMat);
							waitKey(0);
						}*/
						//set thesh1 and thesh2
						int thesh1 = 420;
						int thesh2 = 520;

						int count = 0;  // 统计色值
						for (int x = 0; x < roiMat.rows; x++) {
							for (int y = 0; y < roiMat.cols; y++) {
								if (roiMat.at<uchar>(x, y) == 0) {
									count++;
								}
							}
						}
						if (MAX<count&&count> thesh1){
							MAX = count;
							m = k;
						}
						//printf("i= %d,count=%d,th= %d\n", i + 1, count, thesh2);
						// 超过 50% 算作有效答案
						if (count > thesh2) {
							if (IsJudge){
								k += 9;
							}
							flag = 1;
							switch (k) {
							case 0:
								printf("第 %d 题：A \n", i + 1);
								res += 'A';
								break;
							case 1:
								printf("第 %d 题：B \n", i + 1);
								res += 'B';
								break;
							case 2:
								printf("第 %d 题：C \n", i + 1);
								res += 'C';
								break;
							case 3:
								printf("第 %d 题：D \n", i + 1);
								res += 'D';
								break;
							case 4:
								printf("第 %d 题：E \n", i + 1);
								res += 'E';
								break;
							case 5:
								printf("第 %d 题：F \n", i + 1);
								res += 'F';
								break;
							case 6:
								printf("第 %d 题：G \n", i + 1);
								res += 'G';
								break;
							case 7:
								printf("第 %d 题：H \n", i + 1);
								res += 'H';
								break;
							case 8:
								printf("第 %d 题：I \n", i + 1);
								res += 'I';
								break;
							case 9:
								printf("第 %d 题：T \n", i + 1);
								res += 'T';
								break;
							case 10:
								printf("第 %d 题：F \n", i + 1);
								res += 'F';
								break;
							default:
								break;
							}
							continue;
						}
					}
					if (flag == 0){
						if (IsJudge){
							m += 9;
						}
						switch (m) {
						case -1:
							printf("第 %d 题：  \n", i + 1);
							res += ' ';
							break;
						case 0:
							printf("第 %d 题：A \n", i + 1);
							res += 'A';
							break;
						case 1:
							printf("第 %d 题：B \n", i + 1);
							res += 'B';
							break;
						case 2:
							printf("第 %d 题：C \n", i + 1);
							res += 'C';
							break;
						case 3:
							printf("第 %d 题：D \n", i + 1);
							res += 'D';
							break;	
						case 4:
							printf("第 %d 题：E \n", i + 1);
							res += 'E';
							break;
						case 5:
							printf("第 %d 题：F \n", i + 1);
							res += 'F';
							break;
						case 6:
							printf("第 %d 题：G \n", i + 1);
							res += 'G';
							break;
						case 7:
							printf("第 %d 题：H \n", i + 1);
							res += 'H';
							break;
						case 8:
							printf("第 %d 题：I \n", i + 1);
							res += 'I';
							break;
						case 9:
							printf("第 %d 题：T \n", i + 1);
							res += 'T';
							break;
						case 10:
							printf("第 %d 题：F \n", i + 1);
							res += 'F';
							break;
						case 11:
							printf("第 %d 题： \n", i + 1);
							res += ' ';
							break;
						default:
							break;
						}
					}
					cout << "res:" << res << endl;
					//cout << "realAnswers:" << realAnswers[num][i + 1] << endl;
					cout << "correct:" << correct << endl;
					if (num < realAnswers.size()){
						if (res == realAnswers[num][i + 1]){
							correct++;
						}
					}
				}
				sum_correct += correct;
				printf("acc=%.4f\n", correct / 165.0);
				waitKey(0);
			}
			printf("totoal_acc=%.4f\n", sum_correct / (fileNames.size() * 165));
		}
	}
		//waitKey(0);
	//system("pause");
	return 0;
}