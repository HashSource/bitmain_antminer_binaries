
void LZ4HC_clearTables(LZ4HC_CCtx_internal *hc4)

{
  LZ4HC_CCtx_internal *hc4_local;
  
  memset(hc4,0,0x20000);
  memset(hc4->chainTable,0xff,0x20000);
  return;
}

