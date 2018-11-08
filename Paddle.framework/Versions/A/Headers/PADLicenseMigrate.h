//
//  PADLicenseMigrate.h
//
//  Created by Paddle on 01/09/2018.
//  Introduced in v4.0.
//  Copyright © 2018 Paddle. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

/**
 * @discussion The following constants describe the possible product verification states.
 */
typedef NS_ENUM(NSInteger, PADExistingLicenseType) {
    /**
     * @discussion Specifies that the license is a standard user license
     */
    PADUserLicense,

    /**
     * @discussion Specifies that the license is a v3 style site license
     */
    PADSiteLicense
};

/**
 * @brief The detected license and extracted, relevant details.
 */
@interface PADLicenseMigrateResult : NSObject

@property (nonnull) NSString *activationID;

@property (nonnull) NSString *activationEmail;

@property (nonnull) NSString *licenseCode;

/**
 * @brief The detected license type.
 */
@property PADExistingLicenseType licenseType;

@end

/**
 * @discussion The license migrate delegate is called when an existing v3 style license is found. Returning YES will allow the SDK to migrate this license to v4.
 */
@protocol PADLicenseMigrateDelegate <NSObject>

/**
 * @brief Should the product for ID be migrated from a v3 license to a v4 license
 *
 * @param productId An NSString containing the productId of the product license being migrated.
 * @param existingLicenseType a PADExistingLicenseType ENUM indicating the type of license trying to be migrated
 *
 * @return BOOL to indicate if the license should be migrated to v4
 */
- (BOOL)shouldMigrateExistingV3License:(NSString *)productId type:(PADExistingLicenseType)existingLicenseType;

@end

@interface PADLicenseMigrate : NSObject

@property (weak, nullable) id<PADLicenseMigrateDelegate> delegate;

/**
 * @brief Create a new instance of the PADLicenseMigrate class.
 * @discussion This method is mainly useful for tests so that we can mock the migrator.
 */
+ (instancetype)migrator;

/**
 * @brief Locate and load the v3 license.
 * @return The license details of the v3 license, if any. If no license was found, then \c nil is returned.
 * It's up to the client to merge the license and activation into any license file created by v4 before the migration.
 */
- (nullable PADLicenseMigrateResult *)locateAndLoadExistingV3License:(NSString *)productId;

@end

NS_ASSUME_NONNULL_END
