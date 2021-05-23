#include "Poco.h"

void decrypt_file()
{
    std::istringstream is("-----BEGIN RSA PRIVATE KEY-----\n"
    "Proc-Type: 4,ENCRYPTED\n"
    "DEK-Info: DES-EDE3-CBC,0F9006C4519B55C8\n"
    "\n"
    "rRLQeGPaa8iqc4ke+fxDmCvgfdsgfdsgf55343ggynqDpmhGd29iBed4N1Xovdiw\n"
    "G87l0Uco+ZhsriLPjWBdTmr14HrBxJEJybXucjx1h4WLqMd1ro0QY2QlojJ337Sq\n"
    "LFqcLc1nSW3levjkFIDSpFjnPbaDk/t/1xQEh3VHWOGHa+IVSDKTkw2uyiKO7bh+\n"
    "W6MCbXnaJIS0/6ouoJgnK7COrS/0Hqo5z0wLY9ZCarLeVOYMK+YamhXrSz5sLElI\n"
    "2ysC5kLxhWBZOTiGOc1aPh6svWmFg0I1Eil+PVTR3XR6L/b8LY/BQMh0OJ6uwdvp\n"
    "YfgzdvxqDVbCjw1dNJjgfvegfdgdDDlzQfFsXGf1p9OY0jElL/egVTGP1YLHgMb6\n"
    "zJDUZmgC2PJBOB/KWJF09k0vDfdr/t32OXE9vMPAJeJ2TwecnmvYiLbA5uu93bvi\n"
    "DEo9V+F7ltMS2XQld9kal4dHPE1NdCMBx5oY8Bi+Qf9rXUdO/0JxZIY0j+0pWGZa\n"
    "7iZWriyme4zxGFQJXD8hV4AW7NNUUff3bCkkmYyYOyV11ybWJGGOBk6IJCcuzFoq\n"
    "S94LfFMBtcmXQmUXcQwacIDzAEivmk0Uxz1bMmcu+wNEIquLx9wEZWlll6P88JPv\n"
    "E58HIXKB9AVEJZ5gfdgfdfgregd4345grgdgfs0qbR3v4qcNCKWlihd36MT+0QD+\n"
    "HCoakmTbbPXdUC8HcppB7D9nhjmbuXcneu8sf/zUrDHcwBbHR7T0U63LE2gdzfOc\n"
    "vg6XAhXMRApLYydfsf44sgg4w4wsAcXMJpxNcz+JXG14QcBGJ1Ot4dGbTCVoww==\n"
    "-----END RSA PRIVATE KEY-----\n"
    "\n");

    Poco::Crypto::CipherFactory &factory = Poco::Crypto::CipherFactory::defaultFactory();
    Poco::Crypto::Cipher* pCipher = factory.createCipher(Poco::Crypto::RSAKey(NULL, &is, "my password"));

    // uncomment to read private key from the file
    //Poco::Crypto::Cipher* pCipher = factory.createCipher(Poco::Crypto::RSAKey("", "./private_rsa.pem", "my password"));

    std::ifstream in("./encrypted.bin", std::ios::binary|std::ios::in);
    if(!in.is_open())
        return;

    std::string data;
    data.append(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
    in.close();

    const std::string decrypted_string(pCipher->decryptString(data));
    std::cout << "decrypted string: " << decrypted_string << std::endl;
}