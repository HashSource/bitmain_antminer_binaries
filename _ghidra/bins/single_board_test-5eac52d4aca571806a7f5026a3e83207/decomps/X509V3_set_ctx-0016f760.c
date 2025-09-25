
void X509V3_set_ctx(X509V3_CTX *ctx,X509 *issuer,X509 *subject,X509_REQ *req,X509_CRL *crl,int flags
                   )

{
  ctx->crl = crl;
  ctx->issuer_cert = issuer;
  ctx->flags = flags;
  ctx->subject_cert = subject;
  ctx->subject_req = req;
  return;
}

