
#ifndef TI_OPT_AES_H_
#define TI_OPT_AES_H_

#include "DesFireKey.h"

class AES : public DESFireKey
{
public:
    AES();
    ~AES();
    // theory: you set the key that encodes and decodes using this function
    bool SetKeyData(const byte* u8_Key, int s32_KeySize, byte u8_Version);
    // theory: once setkeydata is called, you just need to call this function to encrypt/decrypt data
    
    bool CryptDataBlock(byte* u8_Out, const byte* u8_In, DESFireCipher e_Cipher);
    
private:
    static void aes_enc_dec(unsigned char state[16], unsigned char key[16], unsigned char dir);
    static unsigned char galois_mul2(unsigned char value);
};

#endif // TI_OPT_AES_H_

