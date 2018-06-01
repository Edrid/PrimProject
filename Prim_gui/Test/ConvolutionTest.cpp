//
// Created by edoardo on 30/05/18.
//

#include <gtest/gtest.h>
#include "../MVC_model/ImageElaborator.cpp"
#include "../MVC_model/UndoManager.cpp"
#include "../MVC_model/FilterApplyer.cpp"
#include "../MVC_model/KernelFilter.cpp"
#include "../MVC_model/GaussianBlur.cpp"
#include "../MVC_model/EdgeDetection.cpp"
#include "../MVC_model/Sharpen.cpp"
#include "../MVC_model/Emboss.cpp"


class ConvolutionTestFixture : public ::testing::Test{
protected:
    ImageElaborator* ie;
    ImageElaborator* imgElab;
    int gaussConvoluted[5][5] = {{0,0,0,0,0},{0,50,50,50,0},{0,50,50,50,0},{0,50,50,50,0},{0,0,0,0,0}};
    int edgeConvoluted[5][5] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    int imageWithEdge[7][7] = {{0,0,0,0,0,0,0},{0,6,117,0,120,9,0},{0,6,117,0,120,9,0},{0,6,117,0,120,9,0},{0,6,117,0,120,9,0},{0,6,117,0,120,9,0},{0,0,0,0,0,0,0}};
    float gaussWithEdge[7][7] = {{0,0,0,0,0,0,0},{0,62,51,40,51,61,0},{0,62,51,40,51,61,0},{0,62,51,40,51,61,0},{0,62,51,40,51,61,0},{0,62,51,40,51,61,0},{0,0,0,0,0,0,0}};
    //TODO fare test su immagini che hanno un contorno
    void SetUp() override{
        imgElab = new ImageElaborator("/home/edoardo/CLionProjects/push/7x7.jpg");
        ie = new ImageElaborator("/home/edoardo/Desktop/immagine prova/rgb50-50-50.jpg");
    }
    void TearDown() override{
        delete ie;
        delete imgElab;
    }
};

TEST_F(ConvolutionTestFixture, matrixDimension){
    ie->filterApplyer_->setKernelStrategy(FilterTypes::EdgeDetection);
    ie->filterApplyer_->kernelFilter();
    EXPECT_EQ(5, ie->getReds().size());
    EXPECT_EQ(5, ie->getReds().at(0).size());
}

TEST_F(ConvolutionTestFixture, edgeConvolution){

    ie->filterApplyer_->setKernelStrategy(FilterTypes::EdgeDetection);
    ie->filterApplyer_->kernelFilter();
    for(int i=0; i<ie->getReds().size(); i++){
        for(int j=0; j<ie->getReds().at(0).size(); j++){
            EXPECT_EQ(edgeConvoluted[i][j], ie->getReds()[i][j]);
        }
    }
}

TEST_F(ConvolutionTestFixture, gaussConvolution){

    ie->filterApplyer_->setKernelStrategy(FilterTypes::GaussianBlur);
    ie->filterApplyer_->kernelFilter();
    for(int i=0; i<ie->getReds().size(); i++){
        for(int j=0; j<ie->getReds().at(0).size(); j++){
            EXPECT_EQ(gaussConvoluted[i][j], ie->getReds()[i][j]);
        }
    }
}

TEST_F(ConvolutionTestFixture, positiveEdgeConvolution){
    imgElab->filterApplyer_->setKernelStrategy(FilterTypes::EdgeDetection);
    imgElab->filterApplyer_->kernelFilter();
    for(int i=0; i<imgElab->getReds().size(); i++) {
        for (int j = 0; j < imgElab->getReds().at(0).size(); j++)
            EXPECT_EQ(imageWithEdge[i][j], imgElab->getReds()[i][j]);

    }
}

TEST_F(ConvolutionTestFixture, positiveGaussConvolution){
    imgElab->filterApplyer_->setKernelStrategy(FilterTypes::GaussianBlur);
    imgElab->filterApplyer_->kernelFilter();
    for(int i=0; i<imgElab->getReds().size(); i++) {
        for (int j = 0; j < imgElab->getReds().at(0).size(); j++)
            EXPECT_EQ(gaussWithEdge[i][j], imgElab->getReds()[i][j]);
    }
}