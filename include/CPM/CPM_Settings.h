












// Idea For Settings:

// Settings Class,

// Allows for registering of settings, saving to and from a file.
// Think of something like:

// Settings::Register<T>(string key, T default value);

// example
// Settings::Register<int>("test setting", 100);

// Also needs to have a way to pre-register settings that will always be there, and there
// values if not detected from a file or something.


// (Alternative is to have Settings class have a way to split settings similar to the 
//  current registry class does. I.E. Settings<CPM> or something) <--- Kind of liking this more
// Then have a Settings_CPM child class that inherits all functionality but seperates to specify
// CPM Settings


// Could look something like:
// Settings_CPM::Register<boolean>("force", true)

// Or:

// Settings<CPM>::Register<boolean>("force", true)


// This way we can also have Settings_Project (Settings<Project>) without having them overlap.