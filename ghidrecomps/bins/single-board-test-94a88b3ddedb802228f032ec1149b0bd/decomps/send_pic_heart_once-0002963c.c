
void send_pic_heart_once(void)

{
  uint local_c;
  
  for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      pic_heart_beat(local_c & 0xff);
    }
  }
  return;
}

