    do
    {
        // set array to dead cells
        do
        {
            system("cls");

            displayMenu();

            setZeroArray(tempArray);

            copyArray(tempArray, currentArray);

            displayArray(currentArray);

            // save and stop array
    //        do
    //        {
                // need to write code for saving arrays

                // play
                do
                {
                    // stop and display current array
                    do
                    {
                        // copy current array and display
                        do
                        {
                            // await user input
                            do
                            {
                                ans = getch();
                                static_cast<char>(tolower(ans));
                                // output initial array
                                if (ans == 'i')
                                {
                                    system("cls" );

                                    displayMenu();

                                    setZeroArray(tempArray);

                                    setInitialPatternArray(tempArray, ans);

                                    copyArray(tempArray, currentArray);

                                    displayArray(currentArray);
                                    breakLoop = true;
                                }
                                else if (ans == 'd')
                                {
                                    // open saved pattern and output array
                                }
                                else if (ans == '1')
                                {
                                    // open pattern 1 and output array
                                }
                                else if (ans == '2')
                                {
                                    // open pattern 2 and output array
                                }
                                else if (ans == '3')
                                {
                                    // open pattern 3 and output array
                                }
                                else if (ans == 't')
                                {
                                    // allow user to input custom pattern
                                }
                                else if (ans == 'q' || ans == 'p' || ans == 'c' || ans == 's')
                                {
                                    breakLoop == true;
                                }
                                else
                                {
                                    system ("cls");

                                    cout << "User has to load pattern." << endl;
                                    cout << "Please try again." << endl;

                                    displayMenu();

                                    displayArray(currentArray);
                                }
                            }
                            while (breakLoop == false);     // pattern has been loaded
                            if (ans == 'q' || ans == 'p' || ans == 'c' || ans == 's')
                            {
                                breakLoop = true;
                            }
                            else
                            {
                                ans = getch();
                            }
                        }
                        while (breakLoop == false);         // incorrect input (#@!...)
                        breakLoop = false;
                        if (ans != 's')
                        {
                            breakLoop = true;
                        }
                    }
                    while (breakLoop == false);           // stop (s)
                }
                while (1)
                {
                    if (userInput = kbhit() && ans != 'q')
                    {
                        displayArray(currentArray);
                        getch();
                    }
                    else if (ans == 'q' || ans == 'c')
                    {
                        breakLoop = true;
                    }
                    else
                    {
                        system("cls");
                        displayMenu();
                        setNextGenArray(currentArray, tempArray);
                        copyArray(currentArray, tempArray);
                        displayArray(currentArray);
                        Sleep(1000);
                    }
                }
                while (breakLoop == false);             // play (p)
                breakLoop = false;
                if (ans != 'c')
                {
                    breakLoop = true;
                }
    //        }
    //        while (breakLoop == false);                 // save (a)
            // save current array to txt file
        }
        while (breakLoop == false)                      // clear (c)
    }
    while (breakLoop == false);                                         // quit (q)
