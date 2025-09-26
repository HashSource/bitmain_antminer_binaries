
void LZ4F_resetDecompressionContext(LZ4F_dctx *dctx)

{
  LZ4F_dctx *dctx_local;
  
  dctx->dStage = dstage_getFrameHeader;
  dctx->dict = (BYTE *)0x0;
  dctx->dictSize = 0;
  dctx->skipChecksum = 0;
  return;
}

