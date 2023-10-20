# 4.4.2
Fixed: Issue introduced in the latest release that was causing the SDK to crash when deactivation method was called

# 4.4.1
- Added dispute/chargeback errors to verification and activation methods for licenses that are associated with orders that have an active dispute/chargeback.
- Implemented internal security updates aimed at minimizing fraudulent activations.
- Improved license verification logic to correctly report unverified activations. Previously, certain scenarios, such as manual removal of an activation via the dashboard, would erroneously trigger an “Unable to verify” error. This has now been fixed and returns the correct state.
- Changed checkout sizing to better support the new checkout design. The new checkout design is wider than previous versions and the SDK checkout window has been updated to accommodate this.
- Fixed popup issues when retrying PayPal payments. Previously, It was possible to open multiple Paypal popup windows for the same checkout, this has now been resolved and we now close the original popup before allowing the buyer to open a new one.
- Addressed an issue that was preventing the local license file expiry date from being updated when calling the verify method, this will cover cases where the license has expired or the expiry has been changed via the dashboard. Previously we were returning the correct error but we were not updating the license file accordingly.

# 4.4.0
- Improvements for SwiftUI - We’ve updated the UI methods to make it easier to use with SwiftUI. Download the updated [Sample app here](https://github.com/PaddleHQ/sdk-mac-v4-sample) where we demonstrate best practices for using the SDK in SwiftUI 
- Ventura UI Updates - The UI has been restructured for Ventura to allow for future customisation and improvements
- Introduction of Activation Reclaim methods - Those will allow you to manage existing/previous activations for a license through the SDK, allowing you to deactivate older activations if the license being used has run out of available activations. - [Please find the documentation here](https://developer.paddle.com/reference/9hswcavs3e1sf-activation-reclaim-mac)
- Fixed memory leaks.
- Resolved deprecations and warnings for macOS Ventura.
- Updated license persistence functionality to switch deprecated unarchiveObjectWithData methods to unarchivedObjectOfClass when using Ventura.


# 4.3.1
Fixed: Prevented verify methods from crashing for particular scenarios when no internet connection was available.

# 4.3.0
This release contains bugs fixes and much-needed improvements which are listed below:
- Switched to WKWebView.
- Removed all semantic warnings.
- Added activation details (`allowed_uses`, `times_used`) to activation calls. This is now on both the activation and verification calls.
- Added error handling on modified properties on the `PADProduct` object.
- Silent activation is now correctly returning errors when used in Swift.
- The Checkout is now returning `PADCheckoutSlowOrderProcessing` state in the completion block for all slow processing orders.
- License verification improvements:
   * Added further checks to obtain the correct machine UUID/MAC address, to help prevent activation issues for certain edge cases.
   * Added a machine UUID error (`-127 “Identifier doesn't match activation”`) for when license verification fails due to the UUID being different from the activation one. This is to help identify more easily when users are trying to activate it on a new machine after migrating to a new one or to make it easy to identify edge cases where the machine’s UUID keeps changing.
   * Added a custom UUID delegate method to allow customization of the user’s machine identifier.


# 4.2.0
Apart from making sure our Mac SDK is ready for the new macOS we’ve also made the following improvements:
- Added allowed_uses and times_used to the license verification response, making it easier to see the user’s remaining activations.
- Improved the activation error handling to display more accurate activation errors.
- Improved core headers.

# 4.1.1
- Support for sandbox environment added (but not subscriptions)
- Tested and updated for macOS Monterey.
- Improved memory leaks.
- Stopped the SDK from generating .profraw/coverage files for certain scenarios.
- Improved Paddle’s Checkout caching behaviour to prevent future issues with paddle.js updates.

If you don’t have a sandbox account yet, you can create one at https://sandbox-vendors.paddle.com/signup.
To use the sandbox environment on the SDK you will need to use `[Paddle setEnvironmentToSandbox];` method before calling any `startLicensing` methods, preferably in `applicationDidFinishLaunching:` and change the vendor id, product id and key to the sandbox values.
Please note that the sandbox only works with one-off SDK products, it does not work with subscription licensing.

# 4.1.0
A universal binary that runs natively on both Apple silicon(M1) and Intel-based Mac computers.

# 4.0.18
Fixed a bug introduced on the last release that was causing trial days to default to zero.
In scenarios where API requests fail, the default product configuration object was not being used, resulting in a non existing trial object and causing the SDK to default to trial expired.

# 4.0.17
This release is compatible with the new MacOS - Big Sur.

Please note that this build does not work on Apple Silicon machines, as the current Xcode GM does not include the ability to build for Apple Silicon just yet. If you have Apple's Developer Transition Kit (DTK) and wish to start testing it please reach out to support@paddle.com. The team will be able to provide you with the current universal beta build and add you to the test list so you can continue to receive our latest betas when a new one is released.

# 4.0.16
- Fixed the issue introduced on the last release that was causing trial days to default to zero.

# 4.0.15

- Memory leaks.
- Deprecated convertPointToBase: in class NSView.
- Added parameters definitions to remove warnings in non-ARC projects.
- Removed unnecessary LLVM instrumentation causing it to write unnecessary default.profraw files.
- License verification race condition issue when offline, this was causing the callbacks to return `.unverified` instead of `.unableToVerify`.
- Incorrect error being passed when
   - More than one error was present
   - A default error would be shown when one was incorrectly caught from the API
- License expiration date was being ignored on activation for licenses with a set expiration date, this caused expired licenses to be successfully activated. Please note that those licenses would then fail license verification verifyActivationWithCompletion. This has now been fixed for all versions of the SDK as the validation is done at API level.

# 4.0.14

Fixed:
- Users being asked to enter the license every time they open the app. Depending on the implementation there was a scenario where changes to a license file wouldn't save (depending on the thread it was on) as it could be locked by another thread. Eg calling refresh inside the completion of verify.
- APP crashes on activation when offline or API is unavailable. 

# 4.0.13
New:
- Added a specific error message when the number of activations for a license runs out.
- Our SDK now understands that sometimes people enter licenses with spaces.
- Added the ability to use your own custom license path.

Fixed:
- Catalina lost license issue

# 4.0.11

New:
- Preliminary support for Paddle subscription licensing.
- Removed Seller App Analytics (analytics.paddle.com) as no-longer supported.
- Added Dutch localizations.

Fixed:
- Crash on JSON Serializer receiving `nil`.
- Custom display type now allows the Seller to do their own UI.
- Crash on `PADInternalAnalyticsEvent` receiving `nil`.

# 4.0.10

New:
- `PADProductDelegate` has a new method of `productPurchased:` which is called when the checkout completes with `PADCheckoutPurchased`.
- Product Access Dialog now supports `PADProduct`s that are Subscription Plans.
- New error code for an invalid API Key `PADAPIErrorBadAPIKey`
- `PADProduct` now has additional Subscription Plan relevant properties such as the recurring price, plan length, etc.

Fixed:
- `PADProduct` License expiry date not being populated.

# 4.0.9

New:
- We no-longer do an automatic refresh of the `PADProduct` provided for `Paddle` initialization if that product has ever been refreshed before.
- Additional property `localizedTrialText` on `PADProduct` and `PADProductConfiguration`, this allows the trial text shown in UI to be localized and not overrided by the remote value in the dashboard.
- "Forgotten License" button added to activation UI to make it easier for end users to find the functionality without Seller intervention.

Fixed:
- Checkout T&Cs and privacy policy now open in the browser for easier reading.

# 4.0.8

New:
- Vastly improved localization support
- Product Configuration now required in scenarios where missing data can cause issues.
- Paddle singleton initialization now accepts a `PaddleDelegate` to allow the error delegate methods to be called in the case of initialization failure.
- `PADProductDelegate` has new activation and deactivation notification methods `productActivated` and `productDeactivated`.
- New `PaddleDelegate` method `canAutoActivate` which if `YES` will automatically silently activate a purchased license key.

Fixed:
- Prompts for keychain access when the keychain considered the app "significantly different", i.e new certificates.
- "Activating License" working UI now easier to read and has rounded corners.
- Checking for v3 license no longer creates the directory if it isn't there.

# 4.0.7

New:
- App Groups support for more flexible v3 -> v4 upgrades.
- Paddle Delegate now informed about failed file system operations.

Fixed:
- Read Only Activation Dialogue text not always easily readable in dark mode.
- Product Access dialogue could display the price as 0 if a Product refresh had been unsuccessful.
- Non-Sheet windows were no longer draggable.

# 4.0.6

New:
- Additional trial tampering security measures for Apple code signed apps.
- New bespoke object for the checkout completion dictionary (`PADCheckoutData`)
- `PADProduct` `lastRefreshDate` now persisted for more finite control of refresh logic.

Fixed:
- Product Info UI being white initially when app is in dark mode.
- `PADProduct` `lastRefreshDate` now being correctly updated on a successful refresh.
- `PADLicenseMigrate` class no-longer public, use `PADProduct` method `migrateV3License` and it's delegate.

# 4.0.5

New:
- License Key Recovery UI flow no-longer offers retry on success.
- Improved support for multiple SDK instances operating under the same bundle ID (plug-ins)
- Added `sdkDirectory` on shared instance to facilitate symlinking of SDK storage location to different directories.
- Added `PADVerificationNoActivation` `PADVerificationState` to clarify when a verification failed based on no local activation to verify, rather than a transmission failure or now deactivated activation.
- Added `PADCheckoutSlowOrderProcessing` `PaddleCheckoutState` for slow order processing edge cases that were previously reported as `PADCheckoutFailed`.
- Added `migrateV3License` to `PADProduct` to allow more control over the flow of events in a v3 -> v4 upgrade. 
- Added `PADTriggeredUITypeFinished` `PADTriggeredUIType` for checkout scenarios where the checkout was successful and previously returned `PADTriggeredUITypeCancel`. For example; when a checkout completes for a non-SDK product and doesn't issue a license code.

Fixed:
- `PADProductDelegate` not always being called on a v3 -> v4 license file migration.
- `PADDefaultConfiguration` local image not being shown when the remote image can not be retrieved.
- Some Activation error messages being blank.

# 4.0.4

Fixed:

- Multiple crashes around patchy connectivity and the checkout flow.
- Timed Trials now more resilient to system clock changes.

# 4.0.3

Fixed
- App Closed Analytics Event not being sent correctly.
- NSTimer method >= 10.12 dependancy removed to return support to >= 10.9.5.
- PaddleAnalyticsKit now correctly exposed.
- Crash at the end of the checkout process in some cases.

# 4.0.2

Fixed
- Some buttons appearing blurry on 10.14 dark mode
- paddleDidError being called with a nil NSError in some cases
- Corrected German localization for Abort to "Abbrechen"
- Analytics not being visible on the vendor dashboard
- "Enter License" checkout button suppressed for Subscription products being purchased
- SDK versioning not being usefully reflected in "get info"

# 4.0.1

New
- Added debug options menu, primarily for manipulating trials.

Fixed
- Crash on initialising a new Product that failed to get an analytics write key.
- Crash on checkout completion for non-licensed products.
- Product Access UI now correctly shows "quit" when there is no associated trial.

# 4.0.0

v4.0 is the next major release of the Mac SDK and while the changes we've made make it easier to have more flexible billing and end user experiences we'll focus here on the integration side (read more info about usage on our blog https://paddle.com/blog/introducing-mac-sdk-v4/).

v4.0 is not a drop in upgrade, you will need to update your implementation (the most common usage we've prepared a migration guide for: https://paddle.com/docs/sdk-migrate-to-v4-mac/)

New
- Reduced singleton complexity, better abstraction of responsibilities to other classes.
- Introduced multiple new classes to handle the above, the most important of which being `PADProduct` which is a local representation of your Paddle Product (or subscription Plan) with properties and methods.
- All UI is now optional, a Paddle delegate method can inform you before we display UI and allow you to customise or intercept the experience.
- A more consistent completion vs delegate methodology, UI notification/control uses delegates and actions (like verify, activate, etc) use completion handlers.
- Dark Mode and 10.14 Mojave support

Important things to be aware of
- This is a new major release, rigorous testing and feedback is encouraged.
- v4.0 only supports direct upgrades from apps using v3 of the SDK (first released 7 Jun 2016).
- v4.0 does not support site licensing, though it can handle upgrades from a site licensed environment.
- v4.0 does not support multi-product licenses.
