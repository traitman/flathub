#include <jxl/decode.h>
#include <stdio.h>
#include <stdlib.h> // Added for exit()

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <input_file.jxl>\n", argv[0]);
    return 1;
  }

  const char *input_file = argv[1];

  // Initialize JxlDecoder
  JxlDecoder *decoder = JxlDecoderCreate(NULL);
  if (!decoder) {
    fprintf(stderr, "Error: Failed to create JxlDecoder\n");
    return 1;
  }

  // Subscribe to decoder events
  JxlDecoderStatus subscribe_status =
      JxlDecoderSubscribeEvents(decoder, JXL_DEC_BASIC_INFO);
  if (subscribe_status != JXL_DEC_SUCCESS) {
    fprintf(stderr, "Error: Failed to subscribe to basic info event\n");
    JxlDecoderDestroy(decoder);
    return 1;
  }

  // Set input file
  FILE *file = fopen(input_file, "rb");
  if (!file) {
    fprintf(stderr, "Error: Failed to open input file\n");
    JxlDecoderDestroy(decoder);
    return 1;
  }

  // Read input file data into memory
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  uint8_t *file_data = (uint8_t *)malloc(file_size);
  if (!file_data) {
    fprintf(stderr, "Error: Memory allocation failed\n");
    fclose(file);
    JxlDecoderDestroy(decoder);
    return 1;
  }
  size_t bytes_read = fread(file_data, 1, file_size, file);
  fclose(file);
  if (bytes_read != file_size) {
    fprintf(stderr, "Error: Failed to read input file\n");
    free(file_data);
    JxlDecoderDestroy(decoder);
    return 1;
  }

  // Set input data in decoder
  JxlDecoderStatus set_input_status =
      JxlDecoderSetInput(decoder, file_data, bytes_read);
  if (set_input_status != JXL_DEC_SUCCESS) {
    fprintf(stderr, "Error: Failed to set input data\n");
    free(file_data);
    JxlDecoderDestroy(decoder);
    return 1;
  }

  // Process the input data
  JxlDecoderStatus process_status = JxlDecoderProcessInput(decoder);
  if (process_status != JXL_DEC_BASIC_INFO) {
    fprintf(stderr, "Error: Failed to process input for basic info\n");
    free(file_data);
    JxlDecoderDestroy(decoder);
    return 1;
  }

  // Get image info
  JxlBasicInfo info;
  JxlDecoderStatus get_info_status = JxlDecoderGetBasicInfo(decoder, &info);
  if (get_info_status != JXL_DEC_SUCCESS) {
    fprintf(stderr, "Error: Failed to get image info\n");
    JxlDecoderDestroy(decoder);
    return 1;
  }

  // Print image info
  printf("Image dimensions: %u x %u\n", info.xsize, info.ysize);
  printf("Color space: %d\n", info.num_color_channels);
  printf("Bit depth: %d\n", info.bits_per_sample);
  printf("Orientation: %d\n", info.orientation);

  // Cleanup
  free(file_data); // Release memory after getting the info
  JxlDecoderDestroy(decoder);

  return 0;
}
