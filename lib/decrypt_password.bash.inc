## decrypt_password - basic decryption
## WARNING: changing $PASSWORD_SALT in ~/etc/init.conf also changes decryption behavior
##
decrypt_password()
{
  local encrypted_password="$1"
  local retval=$INVALID

  retval=$(echo "$encrypted_password"|$BASE64_BIN -d 2>/dev/null|$OPENSSL_BIN des3 -d -k "$PASSWD_SALT")

  echo "$retval"
} ## END: decrypt_password()
