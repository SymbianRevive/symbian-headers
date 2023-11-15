/**
* Copyright (c) 2009 Nokia.
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* 
* @author Initial Contributors: Kari Kostiainen, Nokia Research Center
* @brief Description: The main header (API) of ObC Credentials Manager. 
*/

#ifndef OBC_MANAGER_H
#define OBC_MANAGER_H

#include <e32std.h>
#include <badesca.h>
//#include <flogger.h>
#include "ObcErrors.h"
#include "ObcProgramInfo.h"
#include "ObcSecretInfo.h"
#include "ObcCredInfo.h"
#include "ObcKeyPairInfo.h"

const TInt KObcSKAEChallengeLen = 16;
const TInt KObcAppAuthKeyLen    = 16;
const TInt KObcSignatureLen     = 128;
const TInt KObcCipherTextLen    = 128;
const TInt KObcPubKeyLen        = 162;
const TInt KObcDigestLen        = 20;
const TInt KObcChallengeLen     = 16;

const TInt KObcPinCodeMaxLen    = 20;
const TInt KObcCertReqMaxLen    = 5000;
const TInt KObcProgramMaxLen    = 1500;
const TInt KObcSecretMaxLen     = 500;
const TInt KObcInputMaxLen      = 500;
const TInt KObcOutputMaxLen     = 500;
const TInt KObcEncryptMaxLen    = 117;
const TInt KObcSignMaxLen       = 117;
const TInt KObcCertMaxLen       = 3000;


// certificate subject alternative name OIDs
_LIT(KObcManufacturerOID,  "1.3.6.1.4.1.94.1.49.11.4.1");
_LIT(KObcModelOID,         "1.3.6.1.4.1.94.1.49.11.4.2");
_LIT(KObcImeiOID,          "1.3.6.1.4.1.94.1.49.11.4.3");
_LIT(KObcWlanMacOID,       "1.3.6.1.4.1.94.1.49.11.4.4");
_LIT(KObcBluetoothMacOID,  "1.3.6.1.4.1.94.1.49.11.4.5");

// certificate issuer
_LIT(KObcLevel1CA,    "NOPPA CA for Security Level 1");
_LIT(KObcLevel2CA,    "NOPPA CA for Security Level 2");
_LIT(KObcLevel3CA,    "NOPPA CA for Security Level 3");
_LIT(KObcRootCA,      "NOPPA Root CA");


typedef enum
{
    EInitialized,
    ENotInitialized,
    ENotSupported
} TObcUserAuthMode;

typedef enum 
{
    ESecEnvHardware, 
    ESecEnvEmulatedSecStorage, 
    ESecEnvEmulated 
} TObcSecEnvType;

typedef enum
{
    EDevKeyInternal,
    EDevKeyExternal
} TObcDevKeyType;

typedef enum
{
    EManufacturerID,
    EModelName,
    EIMEI,
    EWlanMAC,
    EBluetoothMAC
} TObcIdentityIndicator;

typedef enum
{
    EDigest,
    EMessage
} TObcSignatureType;

typedef enum
{
    EKeyId,
    ECertIssuer,
    ECertSubject
} TObcCertAttribute;


/** 
 * @class RObcManager ObcManager.h
 * @brief Client interface to Credentials Manager server.
 */
class RObcManager : public RSessionBase
{
public:
    
    /**
     * @brief Establishes connection to Credentials Manager server. 
     * This function must be called before calling any other functions.
     * 
     * Capability:  None
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt Connect();
    
    /**
     * @brief Closes the connection to Credentials Manager server. 
     * This function should be called when everything is completed.
     * 
     * Capability:  None
     * @return      KErrNone or an error code
     */
    IMPORT_C void Close();

    
    // ------------------------------------------------------------
    // AppAuthKey handling
    // ------------------------------------------------------------
    
    /**
     * @brief Generates random application authentication key (AppAuthKey)
     * for this session. The secrets added and key pairs generated during
     * this session can be bound to this AppAuthKey.
     * 
     * Capability:  WriteDeviceData
     * @param[out]  aAppAuthKey The generated key is written to this output 
     *              parameter that must be allocated by the caller.
     * @return      KErrNone or an error code 
     */    
    IMPORT_C TInt NewAppAuthKey(TDes8& aAppAuthKey);
    
    /**
     * @brief Sets an application authentication key (AppAuthKey) for this 
     * session.
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aAppAuthKey
     * @return      KErrNone or an error code 
     */
    IMPORT_C TInt SetAppAuthKey(const TDesC8& aAppAuthKey);

    
    // ------------------------------------------------------------
    // Device initialization functions
    // ------------------------------------------------------------

    /**
     * @brief Check if ObC device keys have been created.
     * 
     * Capability:  ReadDeviceData
     * @return      ETrue if device keys have been created
     * @return      EFalse if device keys have not been created       
     */
    IMPORT_C TBool DeviceKeysCreated();
    
    /**
     * @brief Creates two ObC device keys. The ObC device keys need to be created
     * before some features (e.g. provisioning) of ObC system can be used. 
     * The key creation can take up to one or two minutes, and thus the caller 
     * should inform the user to wait. This operation is asynchronous.
     * 
     * Capability:  WriteDeviceData
     * @param       aStatus The result of the asynchronous operation can be read
     *              from this parameter when key creation is complete.
     */
    IMPORT_C void CreateDeviceKeys(TRequestStatus& aStatus);
    
    /**
     * @brief Delete device keys. This function is allowed only for 
     * ObcConfig wizard.
     * 
     * Capability:  ObcConfig SID
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt DeleteDeviceKeys();
    
    /**
     * @brief Check if certificates for the device keys have been acquired
     * from the device manufacturer.
     * 
     * Capability:  ReadDeviceData
     * @return      ETrue if device keys have been certified
     * @return      EFalse if device keys have not yet been certified
     */
    IMPORT_C TBool DeviceKeysCertified();
    
    /**
     * @brief Check if acquiring device key certificates from the manufacturer
     * is supported in this build.
     * 
     * Capability:  ReadDeviceData
     * @return      ETrue if device key certification is supported
     * @return      EFalse if device key certification is not supported in this build
     */
    IMPORT_C TBool DeviceKeyCertificationSupported();
    
    /**
     * @brief Sets certification server URL. Credentials Manager will
     * remember the URL and use it for all subsequent key certifications
     * untill new server URL is defined.
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aURL The certification server URL 
     * @return      KErrNone if URL was set
     * @return      KErrObcParam if the URL was not acceptable
     *              (e.g. not starting with "http://" or "https://")
     */
    IMPORT_C TInt SetCertificationServerURL(TDesC& aURL);
    
    /**
     * @brief Sends the device keys to device manufacturer for certification.
     * As a result device certificates will be installed to the device. This 
     * operation is asynchronous and requires internet connectivity.
     * 
     * Capability:  WriteDeviceData
     * @param[out]  aStatus contains the result of the asynchronous device
     *              key certification when it is complete 
     */
    IMPORT_C void CertifyDeviceKeys(TRequestStatus& aStatus);
        
    /**
     * @brief Cancels ongoing device key enrollment.
     * 
     * Capabilty:   WriteDeviceData
     */
    IMPORT_C void CancelDeviceKeyCertification();
    
    /**
     * Deletes existing device key certs. This operation is only
     * allowed for ObcConfig wizard.
     * 
     * Capability:  ObcConfig SID
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt DeleteDeviceCerts();
    
    /**
     * @brief Initializes user authentication settings. In practice this
     * means that the user is asked to define a PIN code which will be asked
     * from the user later when a credential or a key pair that requires user
     * authentication is used.
     * 
     * NOTE: Some builds do not support user authentication! This can be 
     * checked with UserAuthSupported() function.
     * 
     * Capability:  WriteDeviceData
     * @return      KErrNone if user authentication was initialized successfully
     * @return      KErrNotSupported if user authentication is not supported
     * @return      KErrObcUserAuthSet if user authentication has alredy been set
     * @return      KErrObcUserAuth if initializing user authentication failed
     */
    IMPORT_C TInt InitUserAuth();

    /**
     * @brief Checks if user authentication has been initialized.
     * 
     * Capability:  ReadDeviceData
     * @return      ETrue if user authentication has been initialized
     * @return      EFalse if user authentication has not been initialized
     */
    IMPORT_C TBool UserAuthInitialized();
    
    /**
     * @brief Checks if user authentication is supported in this build.
     * 
     * Capability:  ReadDeviceData
     * @return      ETrue if user authentication is supported
     * @return      EFalse if user authentication is not supported
     */
    IMPORT_C TBool UserAuthSupported();
    
    /**
     * @brief Reset local user authentication. Allowed only
     * for ObcConfig application.
     * 
     * Capability:  ObcConfig SID
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt ResetUserAuth();
    
    /**
     * @brief Get the used secure environment type. 
     * 
     * Capability:  ReadDeviceData
     * @param[out]  aType Alternatives: EBB5, EEmulatedWithCryptoPA, EEmulated
     * @return      KErrNone or an error code.
     */
    IMPORT_C TInt GetSecEnvType(TObcSecEnvType& aType);
  
    /**
     * @brief Creates an attestation of the calling application. 
     * Application attestation is RSA-SHA1 signature using PKCS#1 v1.5 formatting
     * over type-lenght-value (TLV) data structure defined below:
     * 
     * // version <br>
     * uint8 version_type; // 1 <br>
     * uint16_be version_length; // 1 <br>
     * uint8 version; // 1 <br>
     * 
     * // OS specific application identification information <br>
     * uint8 os_app_id_type; // 2 <br>
     * uint16_be os_app_id_length; // 16 <br>
     * uint8[16] os_app_id; // 8-byte app SID in hex || 8-byte app VID in hex <br>
     *
     * // challenge (typically from external verifier for freshness)<br>
     * uint8 challenge_type; // 3 <br>
     * uint16_be challenge_length; <br>
     * uint8[challenge_length] challenge; <br>
     * 
     * // application provided label <br> 
     * // (e.g. to identify different entities within the app) <br>
     * uint8 label_type;  // 4 <br>
     * uint16_be label_length; <br>
     * uint8[label_length] label; <br>
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aChallenge Typically random challenge from external verifier
     * @param[in]   aLabel String provided by the calling application
     * @param[out]  aAttestationData The signed application attestation data structure
     * @param[out]  aSignature Resulting attestation signature
     */
    IMPORT_C TInt AppAttest(const TDesC8& aChallenge, 
            const TDesC8& aLabel,
            TDes8& aAttestationData,
            TDes8& aSignature);

    
    // ------------------------------------------------------------
    // Symmetric credentials
    // ------------------------------------------------------------
    
    /**
     * @brief Installs provisioned program into ObC database. 
     *  
     * Capability:  WriteDeviceData
     * @param[in]   aInit ObCP/Init provisioning package    
     * @param[in]   aXfer ObCP/Xfer provisioning package
     * @param[in]   aInfo Optional attributes about the program
     * @return      ProgramId or an error code
     */
    IMPORT_C TInt AddProvProgram(const TDesC8& aInit, 
            const TDesC8& aXfer, 
            const TObcProgramInfo& aInfo = TObcProgramInfo());  

    /**
     * @brief Installs plaintext program into ObC database.
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aProgram Credential program bytecode
     * @param[in]   aInfo Optional attributes about the program
     * @return      ProgramId or an error code
     */
    IMPORT_C TInt AddProgram(const TDesC8& aProgram, 
            const TObcProgramInfo& aInfo = TObcProgramInfo());
    
    /**
     * @brief Get list of TObcProgramInfo structures. This list can 
     * be enumerated to find the correct program from the database.
     * 
     * Capability:  ReadDeviceData
     * @param[out]  aInfos List of TObcProgramInfo structures is written to this
     *              output parameter that must be allocated by the caller.
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt GetProgramInfosL(RArray<TObcProgramInfo>& aInfos);

    /**
     * @brief Get the number of programs in database.
     * 
     * Capability:  ReadDeviceData
     * @return      The number of programs or error code
     */
    IMPORT_C TInt GetProgramsCount();    
    
    /**
     * @brief Deletes a program from the database. The program can only
     * be deleted by the owner of the program (the app that added the program)
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aProgramId The program to delete
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt DeleteProgram(TInt aProgramId);
    
    /**
     * @brief Deletes all programs owned (added) by this application. 
     * 
     * Capability:  WriteDeviceData
     * @return      The number of programs deleted or an error code
     */
    IMPORT_C TInt DeleteAllPrograms();
    
    /**
     * @brief Installs provisioned secret into ObC database. 
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aInit ObCP/Init provisioning package
     * @param[in]   aXfer ObCP/Xfer provisioning packager
     * @param[in]   aInfo Optional attributes about the secret
     * @return      SecretId or an error code
     */
    IMPORT_C TInt AddProvSecret(const TDesC8& aInit, 
            const TDesC8& aXfer, 
            const TObcSecretInfo& aInfo = TObcSecretInfo());

    /**
     * @brief Installs plaintext secret into ObC database. 
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aSecret The secret. Notice that ObC Interpreter operates with
     *              16-bit big-endian shorts.
     * @param[in]   aInfo Optional attributes about the secret
     * @return      SecretId or an error code
     * 
     */
    IMPORT_C TInt AddSecret(const TDesC8& aSecret, 
            const TObcSecretInfo& aInfo = TObcSecretInfo());

    /**
     * @brief Gets list of all secret infos. 
     * 
     * Capability:  ReadDeviceData
     * @param[out]  aInfos 
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt GetSecretInfosL(RArray<TObcSecretInfo>& aInfos);

    /**
     * @brief Returns the number of secrets in database.
     * 
     * Capability:  ReadDeviceData
     * @return      The number of secrets or an error code (negative)
     */
    IMPORT_C TInt GetSecretsCount(); 
    
    /**
     * @brief Deletes a secret from database. The secret can only be deleted
     * by the owner application (the app that originally added the secret). 
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aSecretId Identifier of the secret to delete
     * @return      KErrNone or an error code 
     */
    IMPORT_C TInt DeleteSecret(TInt aSecretId);
    
    /**
     * @brief Deletes all secrets owned (added) by the calling application. 
     * 
     * Capability:  WriteDeviceData
     * @return      The number of secrets deleted or an error code 
     */
    IMPORT_C TInt DeleteAllSecrets();
    
    /**
     * @brief Creates a credential by endorsing a program to a secret. 
     * If the secret was provisioned, proper endorsement package must 
     * be provided as a parameter. If the secret requires application
     * authentication based on AppAuthKey, SetAppAuthKey() must be
     * called with the correct key before using this function.
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aProgramId The credential program identifier         
     * @param[in]   aSecretId The credential secret identifier
     * @param[in]   aInfo (Optional) Attributes about the created credential
     * @param[in]   aEndorse (Optional) ObCP/Endorsement package. Needed for
     *              provsioned secrets.
     * @return      CredentialId or error code
     */
    IMPORT_C TInt CreateCredential(TInt aProgramId, 
            TInt aSecretId, 
            const TObcCredInfo& aInfo = TObcCredInfo(), 
            const TDesC8& aEndorse = KNullDesC8);

    /**
     * @brief Executes single-input single-output credential. Notice that
     * the ObC Interpreter operates with 16-bit big-endian values.
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aCredentialId The identifier of the credential
     * @param[in]   aInput The input for credential execution 
     * @param[out]  aOutput The output of credential execution
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt UseCredentialL(TInt aCredentialId, 
            const TDesC8& aInput, 
            TDes8& aOutput);
    
    /**
     * @brief Executes credential with multiple inputs and multiple
     * outputs. Notice that the ObC Interpreter operates with 16-bit 
     * big-endian values.
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aCredentialId The identifier of the credential
     * @param[in]   aInputs Application inputs array
     * @param[out]  aOutputs Credential outputs array
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt UseCredentialL(TInt aCredentialId, 
            CDesC8Array* aInputs, 
            CDesC8Array* aOutputs);
    
    /**
     * @brief Get list of credentials infos. The the correct credential
     * can be found by enumerating this list. 
     * 
     * Capability:  ReadDeviceData
     * @param[out]  aInfos An array of credential infos
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt GetCredentialInfosL(RArray<TObcCredInfo>& aInfos);
    
    /**
     * @brief Get the number of credentials in database.
     * 
     * Capability:  ReadDeviceData
     * @return      The number of credentials or an error code
     */
    IMPORT_C TInt GetCredentialsCount(); 
    
    /**
     * @brief Deletes a credential from the database. The credential
     * must be owned (created) by this app. 
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aCredentialId   TInt    The credential id to delete
     * @return      Error code
     */
    IMPORT_C TInt DeleteCredential(TInt aCredentialId);

    /**
     * @brief Deletes all credentials (owned by the caller application). 
     * 
     * Capability:  WriteDeviceData
     * @return      Error code
     */
    IMPORT_C TInt DeleteAllCredentials();

     
    // ------------------------------------------------------------
    // Key pair functions
    // ------------------------------------------------------------
    
    /**
     * @brief Generates a key pair synchronously (blocking function). 
     * UI applications should use the asynchronous version of CreateKeyPairL().
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aInfo (Optional) Defines attributes for the generated key
     * @return      KeyPairId or an error code
     */
    IMPORT_C TInt CreateKeyPair(const TObcKeyPairInfo& aInfo = TObcKeyPairInfo());
        
    /**
     * @brief Generates key pair asynchronously. This operation, should be 
     * used from an active object.    
     * 
     * Capability:  WriteDeviceData
     * @param[out]  aStatus Contains the key pair Id (aStatus.Int()) when
     *              the asynchronous key pair generation is complete.
     * @param[in]   aInfo (Optional) defines attributes for genrated key.
     */
    IMPORT_C void CreateKeyPair(TRequestStatus& aStatus, 
            const TObcKeyPairInfo& aInfo = TObcKeyPairInfo());
           
    /**
     * @brief Get all key pair info structures. The calling application can 
     * enumerate through the info structures and select right key pair based 
     * on key pair name, usage, creator, size etc. 
     * 
     * Capability:  ReadDeviceData
     * @param[out]  aInfos An array of key pairs of all key pairs in 
     *              the Obc Database
     * @return      Error code
     */
    IMPORT_C TInt GetKeyPairInfosL(RArray<TObcKeyPairInfo>& aInfos);
    
    /**
     * @brief Get the public part of a key pair.
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aKeyPairId Defines the key pair
     * @param[out]  aPublicKey The public key is written into this output 
     *              parameter that must be allocated by the caller. The public 
     *              key is ASN.1 DER encoded SubjectPublicKeyInfo structure 
     *              (openssl defacto standard). 
     * @return      Error code
     */
    IMPORT_C TInt GetPublicKey(TInt aKeyPairId, TDes8& aPublicKey);

    /**
     * @brief Get PKCS#10 certificate request for a given key pair. The
     * caller may use this cert request to get the key certified.
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aKeyPairId Specifies the key pair to use
     * @param[out]  aCertRequest PCKS#10 formatted certificate request is
     *              written to this parameter that must be allocated by the
     *              calling application. 
     * @return      Error code
     */
    IMPORT_C TInt GetKeyPairCertRequest(TInt aKeyPairId, 
            TDes8& aCertRequest);

    /**
     * @brief Creates PKCS#10 certificate request with ObC-SKAE extension
     * for given key pair. The caller may use this cert request to get the
     * key certified. This function is supported only for builds in which
     * device key certification is supported. 
     * 
     * Capability:  ReadDeviceData
     * 
     * @param[in]   aKeyPairId Specifies the key pair to use
     * @param[in]   aChallenge Challenge from atterstor (16 bytes).
     * @param[out]  aCertRequest PCKS#10 formatted certificate request that contains
     *              ObC specific internal SKAE as an extension. 
     *              
     * @return      KErrNone for successful cert request creation
     * @return      KErrObcNoDevKeys if device keys have not been initialized
     * @return      KErrObcNoDevKeyCert if device keys have not been certified
     * @return      KErrNotSupported if device key certification is not supported
     */
    IMPORT_C TInt GetCertRequestWithSKAE(TInt aKeyPairId, 
            const TDesC8& aChallenge,
            TDes8& aCertRequest);
    
    /**
     * @brief Runs key certification protocol (NOPPA). Asynchronous operation, 
     * requires Internet access. The resulting certificate is stored into 
     * ObC database and written to output parameter. Returns (in aStatus) 
     * either identifier of the stored certificate or error code. 
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aKeyPairId The key that should be certified
     * @param[in]   aIndicator Defines which device identifier is used as
     *              certificate subject. Possible values:
     *                  - EManufacturerID
     *                  - EModelName
     *                  - EIMEI
     *                  - EWlanMAC
     *                  - EBluetoothMAC
     * @param[out]  aStatus The return value of the asynchronous operation
     *              can be read from aStatus. Non-negative value is the
     *              identifier of stored certificate. Negative value is error code. 
     * @param[out]  aCert The resulting certificate is written here
     */
    IMPORT_C void CertifyKeyPair(TInt aKeyPairId, 
            TObcIdentityIndicator aIndicator,
            TRequestStatus& aStatus,
            TDes8& aCert);
    
    /**
     * @brief Creates a self-signed certificate for a key with following
     * information:
     *  - serial number: 1
     *  - notBefore: 2010-01-01
     *  - notAfter: 2100-01-01
     *  - subjectDN: CN=Self-signed certificate
     *  - issuerDN: CN=Self-signed certificate
     *  - no extensions
     * The created certificate is stored into database and certificate 
     * identifier is returned. 
     *  
     * Capability:  WriteDeviceData
     * @param[in]   aKeyPairId Identifies the key for which the self-signed cert
     *              should be created for
     * @param[out]  aCert The resulting certificate
     * @return      Identifier of the certificate (non-negative) if success 
     *              or error code (negative) 
     */
    IMPORT_C TInt CreateSelfSignedCert(TInt aKeyPairId,
            TDes8& aCert);
    
    /**
     * @brief Adds an entity certificate for chosen key pair.
     * 
     * Capability:  WriteDeviceData
     * @param       aKeyPairId Identifier of the key pair that the entity 
     *              certificate is for
     * @param       aCert X.509v3 certificate in ASN.1 encoded format
     * @return      Unique identifier for the certificate (non-negative) if success, 
     *              otherwise an error code (negative)
     */
    IMPORT_C TInt AddEntityCert(TInt aKeyPairId, 
            const TDesC8& aCert);
        
    /**
     * @brief Get stored entity certificate from database.
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aCertId Identifier of the certificate
     * @param[out]  aCert Certificate is written to this parameter if found 
     * @return      KErrNone or an error code 
     */
    IMPORT_C TInt GetEntityCert(TInt aCertId,
            TDes8& aCert);
    
    /**
     * @brief Find entity certificate(s) from database that match given
     * search attribute.
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aAttribute Search attribute. Possible values: 
     *              EKeyId, ECertIssuer, ECertSubject
     * @param[in]   aValue Pointer to certificate attrbute. In case of EKeyId pointer
     *              to TInt. In case of ECertIssuer or ECertSubject pointer to TDesC.
     * @param[out]  aCerts An array of all certificates that match the search criteria.
     * @return      Number of certs found (non-negative) or error code (negative)
     */
    IMPORT_C TInt FindEntityCerts(TObcCertAttribute aAttribute,
            void* aValue,
            CDesC8Array* aCerts);
    
    /**
     * @brief Deletes an entity certificate from database
     *
     * Capability:  WriteDeviceData
     * @param[in]   aCertId Identifier of the entity certiticate 
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt DeleteEntityCert(TInt aCertId);
    
    /**
     * @brief Get the number of key pairs in database.
     * 
     * Capability:  ReadDeviceData
     * @return      The number of programs or an error code.
     */
    IMPORT_C TInt GetKeyPairsCount(); 
    
    /**
     * @brief Deletes a key pair from the database. The key pair
     * must be owned by the caller.
     * 
     * Capability:  WriteDeviceData
     * @param[in]   aKeyPairId The key pair to delete
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt DeleteKeyPair(TInt aKeyPairId);
    
    /**
     * @brief Deletes all key pairs owned by the caller
     * 
     * Capability:  WriteDeviceData
     * @return      The number of deleted key pairs or an error code.
     */
    IMPORT_C TInt DeleteAllKeyPairs();
    
    /**
     * @brief Decrypts data using the private part of the key pair inside
     * the secure environment. The decryption is done according to PKCS#1 v1.5.
     * 
     * Capability:  NetworksServices
     * @param[in]   aKeyPairId Specifies the key pair to use.
     * @param[in]   aCipherText The data to decrypt
     * @param[out]  aPlainText The resulting plain text data
     * @return      KErrNone or an error code
     */ 
    IMPORT_C TInt Decrypt(TInt aKeyPairId, 
            const TDesC8& aCipherText, 
            TDes8& aPlainText);

    /**
     * @brief Encrypts data using caller provided public key. This operation 
     * is not executed in the secure environment and this function is provided 
     * mostly as a convenience.  
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aPublicKey The public key must be ASN.1 DER encoded 
     *              SubjectPublicKeyInfo structure.
     * @param[in]   aData The data to encrypt (KObcEncryptMaxLen = 117 bytes)
     * @param[out]  aCipherText The resulting encrypted data (128 bytes)
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt Encrypt(const TDesC8& aPublicKey, 
            const TDesC8& aData, 
            TDes8& aCipherText);
    
    /** 
     * @brief Signs data using private key within the sescure environment.
     * The signature type defines acceptable input data:
     *      
     *      EMessage - Input data can have arbitrary lenght. RSA-SHA1 signature
     * is calculated using PCKS#1 v1.5 padding.    
     *      EDigest - Input data must be 20-byte SHA-1 digest. RSA-SHA1 signature
     * is calculated over the digest using PKCS#1 v1.5 padding.    
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aType Defines signature type (EMessage or EDigest)
     * @param[in]   aKeyPairId Defines the key pair to use
     * @param[in]   aData The data to sign (in case of EDigest must be exactly 20 bytes)
     * @param[out]  aSignature The resulting signature
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt Sign(const TObcSignatureType aType,
            TInt aKeyPairId,
            const TDesC8& aData, 
            TDes8& aSignature);
    
    /**
     * @brief Verifies a signature using public key. 
     * Verification is not executed in the secure environment and this 
     * function is provided mostly as a convenience. The signature data defines
     * acceptable input data:
     * 
     *      EMessage - The whole signed data (may be arbitrary length)
     *      EDigest - SHA-1 digest of signed data (must be 20 bytes)
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aType Defines signature type (EMessage or EDigest)
     * @param[in]   aPublicKey  The public key of signing key pair. Must be
     *              ASN.1 DER encoded SubjectPublicKeyInfo structure.
     * @param[in]   aSignature  The signature (always 128 bytes)
     * @param[in]   aData const The signed data
     * @param[out]  aValid      ETrue if signature is valid, EFalse otherwise          
     * @return      Error code
     */
    IMPORT_C TInt Verify(const TObcSignatureType aType,
            const TDesC8& aPublicKey,
            const TDesC8& aSignature, 
            const TDesC8& aData, 
            TBool& aValid);
      
   
    // ------------------------------------------------------------
    // Device key pair functions
    // ------------------------------------------------------------
    
    /**
     * @brief Get the public part of the device key pairs. The public key 
     * is written to output parameter that must be allocated by the caller.  
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aType Type of the device key (EDevKeyInternal or 
     *              EObcDevKeyExternal)
     * @param[out]  aPublicKey The public key is written to this output
     *              parameter in SubjectPublicKeyInfo format
     * @return      Error code
     */
    IMPORT_C TInt GetDevicePubKey(TObcDevKeyType aType, 
            TDes8& aPublicKey);
    
    /**
     * @brief Get the lenght of specified device certificate.
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aType Device key type (EDevKeyInternal or EDevKeyExternal)
     * @return      Device certificate length or an error code (negative) 
     */
    IMPORT_C TInt GetDeviceCertLen(TObcDevKeyType aType);
       
    /**
     * @brief Get certificate of the device key pair 
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aType Type of device key (EDevKeyInternal or EDevKeyExternal)
     * @param[out]  aCert The device certificate in X.509 format.
     * @return      Error code
     */
    IMPORT_C TInt GetDeviceCert(TObcDevKeyType aType, 
            TDes8& aCert);
    
    /**
     * @brief Get CA certificate chain for device key certificates. 
     * 
     * Capability:  ReadDeviceData
     * @param[out]  aCertChain List of CA certificates is written to this output 
     *              parameter. The caller must allocate and free this variable.
     * @return      Error code
     */
    IMPORT_C TInt GetDeviceCertCAChainL(CDesC8Array* aCertChain);
     
    
    // ------------------------------------------------------------
    // Backup and restoring
    // ------------------------------------------------------------
    
    /**
     * @brief Performs disabling backup to a server.
     * NOTE: Not supported currently! 
     * 
     * Capability:  Nokia VID
     * @return      Error code
     */
    IMPORT_C TInt DisablingBackup();
    
    /**
     * @brief Restores credentials backup from a server.
     * NOTE: Not supported currently!
     * 
     * Capability:  Nokia VID
     * @return      Error code 
     */
    IMPORT_C TInt RestoreBackup();


    // ------------------------------------------------------------
    // Service tag functionality
    // ------------------------------------------------------------

    /**
     * @brief Gets a ServiceTag response from Service Tag PA. 
     * The backend data that is used is of following format: 
     * "OviAuthentication" || challenge.
     * 
     * Capability:  Nokia VID and ReadDeviceData
     * @param[in]   aChallenge Challenge e.g. from the server.
     * @param[out]  aResponse The actual ServiceTag response.
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt ServiceTag(const TDesC8& aChallenge, 
            TDes8& aResponse);
    
    /**
     * @brief Signs data using hardware device key (Service Tag PA signature)
     * 
     * Capability:  ReadDeviceData
     * @param[in]   aData The data to-be-signed (KObcSignatureMaxLen=117)
     * @param[out]  aSignature The resulting signature (always 128 bytes) 
     * @return      KErrNone or and error code
     */
    IMPORT_C TInt HardwareKeySignature(const TDesC8& aData, 
            TDes8& aSignature);
    
    /**
     * @brief Get certificate for hardware device key signatures
     * 
     * Capability:  ReadDeviceData
     * @param[out]  aCert Hardware key certificate 
     * @return      KErrNone or an error code
     * 
     */
    IMPORT_C TInt GetHardwareKeyCert(TDes8& aCert);
    
    
    // ------------------------------------------------------------
    // Misc
    // ------------------------------------------------------------
    
    /**
     * @brief Provides direct access from an application to a chosen PA.
     * Intended for internal test/development use only. Requires Nokia
     * vendor ID.
     * 
     * Capability:  Nokia VID and ReadDeviceData
     * @param[in]   aPaId Identifier of ObC PA
     * @param[in]   aInput Input data      
     * @param[out]  aOutput Output data
     * @return      KErrNone or an error code
     */
    IMPORT_C TInt DirectAccess(TInt aPaId, 
            const TDesC8& aInput, 
            TDes8& aOutput);
    
private:
    TInt StartServer();   
    void ParseInfos(const TDesC8& aBuf, RArray<TObcProgramInfo>& aInfos);
    void ParseInfos(const TDesC8& aBuf, RArray<TObcSecretInfo>& aInfos);
    void ParseInfos(const TDesC8& aBuf, RArray<TObcCredInfo>& aInfos);
    
    TBuf8<200> iKeyPairInfoBuf;
};


#endif
