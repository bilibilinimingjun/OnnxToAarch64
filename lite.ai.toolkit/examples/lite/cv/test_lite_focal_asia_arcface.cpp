//
// Created by DefTruth on 2021/7/7.
//

#include "lite/lite.h"

static void test_default()
{
  std::string onnx_path = "../../../examples/hub/onnx/cv/focal-arcface-bh-ir50-asia.onnx";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_1.png";

  lite::cv::faceid::FocalAsiaArcFace *focal_asia_arcface = new lite::cv::faceid::FocalAsiaArcFace(onnx_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  focal_asia_arcface->detect(img_bgr0, face_content0);
  focal_asia_arcface->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "Default Version Detected Sim: " << sim << std::endl;
  }

  delete focal_asia_arcface;
}

static void test_onnxruntime()
{
#ifdef ENABLE_ONNXRUNTIME
  std::string onnx_path = "../../../examples/hub/onnx/cv/focal-arcface-bh-ir50-asia.onnx";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_2.png";

  lite::onnxruntime::cv::faceid::FocalAsiaArcFace *focal_asia_arcface =
      new lite::onnxruntime::cv::faceid::FocalAsiaArcFace(onnx_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  focal_asia_arcface->detect(img_bgr0, face_content0);
  focal_asia_arcface->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "ONNXRuntime Version Detected Sim: " << sim << std::endl;
  }

  delete focal_asia_arcface;
#endif
}

static void test_mnn()
{
#ifdef ENABLE_MNN
  std::string mnn_path = "../../../examples/hub/mnn/cv/focal-arcface-bh-ir50-asia.mnn";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_2.png";

  lite::mnn::cv::faceid::FocalAsiaArcFace *focal_asia_arcface =
      new lite::mnn::cv::faceid::FocalAsiaArcFace(mnn_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  focal_asia_arcface->detect(img_bgr0, face_content0);
  focal_asia_arcface->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "MNN Version Detected Sim: " << sim << std::endl;
  }

  delete focal_asia_arcface;
#endif
}

static void test_ncnn()
{
#ifdef ENABLE_NCNN
  std::string param_path = "../../../examples/hub/ncnn/cv/focal-arcface-bh-ir50-asia.opt.param";
  std::string bin_path = "../../../examples/hub/ncnn/cv/focal-arcface-bh-ir50-asia.opt.bin";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_2.png";

  lite::ncnn::cv::faceid::FocalAsiaArcFace *focal_asia_arcface =
      new lite::ncnn::cv::faceid::FocalAsiaArcFace(param_path, bin_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  focal_asia_arcface->detect(img_bgr0, face_content0);
  focal_asia_arcface->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "NCNN Version Detected Sim: " << sim << std::endl;
  }

  delete focal_asia_arcface;
#endif
}

static void test_tnn()
{
#ifdef ENABLE_TNN
  std::string proto_path = "../../../examples/hub/tnn/cv/focal-arcface-bh-ir50-asia.opt.tnnproto";
  std::string model_path = "../../../examples/hub/tnn/cv/focal-arcface-bh-ir50-asia.opt.tnnmodel";
  std::string test_img_path0 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_0.png";
  std::string test_img_path1 = "../../../examples/lite/resources/test_lite_focal_asia_arcface_2.png";

  lite::tnn::cv::faceid::FocalAsiaArcFace *focal_asia_arcface =
      new lite::tnn::cv::faceid::FocalAsiaArcFace(proto_path, model_path);

  lite::types::FaceContent face_content0, face_content1;
  cv::Mat img_bgr0 = cv::imread(test_img_path0);
  cv::Mat img_bgr1 = cv::imread(test_img_path1);
  focal_asia_arcface->detect(img_bgr0, face_content0);
  focal_asia_arcface->detect(img_bgr1, face_content1);

  if (face_content0.flag && face_content1.flag)
  {
    float sim = lite::utils::math::cosine_similarity<float>(
        face_content0.embedding, face_content1.embedding);
    std::cout << "TNN Version Detected Sim: " << sim << std::endl;
  }

  delete focal_asia_arcface;
#endif
}

static void test_lite()
{
  test_default();
  test_onnxruntime();
  test_mnn();
  test_ncnn();
  test_tnn();
}

int main(__unused int argc, __unused char *argv[])
{
  test_lite();
  return 0;
}
