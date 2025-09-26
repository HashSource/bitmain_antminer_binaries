
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void start_upload_repaire_data(void)

{
  pthread_t repaire_thread;
  
  if ((Local_Config_Information->Repair_Mode).Enable_Repair != false) {
    repaire_thread = 0;
    pthread_create(&repaire_thread,(pthread_attr_t *)0x0,(__start_routine *)0xbbfc5,(void *)0x0);
  }
  return;
}

