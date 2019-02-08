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
