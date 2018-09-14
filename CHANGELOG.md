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
