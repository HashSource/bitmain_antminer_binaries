
void pic_heart_beat_func(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  do {
    heart_beat_PIC16F1704(uVar1,uVar2);
    sleep(10);
  } while( true );
}

