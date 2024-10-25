#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include<vector>
#include<string>
int main(){
    cv:: Mat src, gray_src, drawImg, bin_output;
    src = cv::imread( "/root/long/extra.jpg", 1 );//下载
    cv::cvtColor(src, gray_src, cv::COLOR_RGB2GRAY);//灰度
    cv::threshold( gray_src, bin_output,230, 255, 3 );//二值化

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(bin_output, contours,1,2);//找轮廓
    src.copyTo(drawImg);
    cv:: drawContours( src , contours, -1, (100,20,50),5);


    cv:: RotatedRect RotatedRect;
    double MinArea = 10 ;
    double MaxArea = 1000 ;//筛选
    for(int i =0;i<contours.size();i++){//画画
        for(int i =0;i<contours.size();i++){
        if(MinArea<cv:: contourArea(contours[i])&&cv:: contourArea(contours[i])< MaxArea){
        RotatedRect  = cv:: minAreaRect(contours[i]);}
        float angle = RotatedRect.angle;
        if(angle <= 10 || angle>=80){
        cv:: Point2f pst[4];
        RotatedRect.points(pst);
        for(int u =0; u < 4;u++)
        {
            line(drawImg, pst[u], pst[(u + 1) % 4], (0, 0,250),2, 8);
        }
        }}
    }
    
    



    cv::imshow("test",src);
    cv::imshow("output",drawImg);
    cv::imshow("Black and White",bin_output);
    cv::waitKey(0);

    return 0;




}