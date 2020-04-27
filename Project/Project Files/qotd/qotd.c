#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE2(qotd, int, month, int, day)
{

    char *january_quotes[] = {
        "New year— a new chapter, new verse, or just the same old story? Ultimately we write it. The choice is ours. - Alex Morritt", // 1/1 Alex Morritt
        "Do not mind anything that anyone tells you about anyone else. Judge everyone and everything for yourself - Henry James",     // 1/2 Henry James
        "Let us sacrifice our today so that our children can have a better tomorrow. - A.P.J. Abdul Kalam",                           // 1/3 A.P.J. Abdul Kalam
        "You cannot shake hands with a clenched fist. - Indira Gandhi",                                                               // 1/4 Indira Gandhi
        "There is nothing permanent except change. - Heraclitus",                                                                     // 1/5 Heraclitus
        "When you reach the end of your rope, tie a knot in it and hang on. - Franklin D. Roosevelt",                                 // 1/6 Franklin D. Roosevelt
        "Learning never exhausts the mind. - Leonardo da Vinci",                                                                      // 1/7 Leonardo da Vinci
        "There is no charm equal to tenderness of heart. - Jane Austen",                                                              //1/8 Jane Austen
        "All that we see or seem is but a dream within a dream. - Edgar Allan Poe",                                                   // 1/9 Edgar Allan Poe
        "If you cannot do great things, do small things in a great way. - Napoleon Hill",                                             // 1/10 Napoleon Hill
        "Independence is happiness. - Susan B. Anthony",                                                                              // 1/11 Susan B. Anthony
        "The supreme art of war is to subdue the enemy without fighting. - Sun Tzi",                                                  // 1/12 Sun Tzi
        "Keep your face always toward the sunshine — and shadows will fall behind you. - Walt Whitman",                               // 1/13 Walt Whitman
        "Being entirely honest with oneself is a good exercise. - Sigmund Freud",                                                     // 1/14 Sigmund Freud
        "Happiness can exist only in acceptance. - George Orwell",                                                                    // 1/15 George Orwell
        "Love had no age, no limit; and no death. - John Galsworthy",                                                                 // 1/16 John Galsworthy
        "You can't blame gravity for falling in love. - Albert Einstein",                                                             // 1/17 Albert Einstein
        "There is only one corner of the universe you can be certain of improving, and that's your own self. - Aldous Huxley",        // 1/18 Aldous Huxley
        "Honesty is the first chapter in the book of wisdom. - Thomas Jefferson",                                                     // 1/19 Thomas Jefferson
        "The journey of a thousand miles begins with one step. - Lao Tzu",                                                            //1/20 Lao Tzu
        "The best preparation for tomorrow is doing your best today. - H. Jackson Brown, Jr.",                                        // 1/21 H. Jackson Brown, Jr.
        "There are two ways of spreading light: to be the candle or the mirror that reflects it. - Edith Wharton",                    // 1/22 Edith Wharton
        "God gave us the gift of life; it is up to us to give ourselves the gift of living well. - Voltaire",                         // 1/23 Voltaire
        "Coming together is a beginning; keeping together is progress; working together is success. - Edward Everett Hale",           // 1/24 Edward Everett Hale
        "Change your life today. Don't gamble on the future, act now, without delay. - Simone de Beauvoir",                           // 1/25 Simone de Beauvoir
        "Not all those who wander are lost. - J.R.R. Tolkien",                                                                        // 1/26 J.R.R. Tolkien
        "Whoever is happy will make others happy too. - Anne Frank",                                                                  // 1/27 Anne Frank
        "I have not failed. I've just found 10,000 ways that won't work. - Thomas A. Edison",                                         // 1/28 Thomas A. Edison
        "Tell me and I forget. Teach me and I remember. Involve me and I learn. - Benjamin Franklin",                                 // 1/29 Benjamin Franklin
        "There is nothing on this earth more to be prized than true friendship. -  Thomas Aquinas",                                   // 1/30 Thomas Aquinas
        "A leader is one who knows the way, goes the way, and shows the way. - John C. Maxwell"                                       // 1/31 John C. Maxwell
    };

    char *february_quotes[] = {
        "Very little is needed to make a happy life; it is all within yourself, in your way of thinking. -  Marcus Aurelius",                            // 2/1 Marcus Aurelius
        "There is only one happiness in this life, to love and be loved. - George Sand",                                                                 // 2/2 George Sand
        "If opportunity doesn't knock, build a door. - Milton Berle",                                                                                    // 2/3 Milton Berle
        "The secret of getting ahead is getting started. - Mark Twain",                                                                                  // 2/4 Mark Twain
        "Let us be grateful to people who make us happy, they are the charming gardeners who make our souls blossom. - Marcel Proust",                   // 2/5 Marcel Proust
        "Always remember that you are absolutely unique. Just like everyone else. - Margaret Mead",                                                      // 2/6 Margaret Mead
        "Wise men speak because they have something to say; fools because they have to say something. - Plato",                                          // 2/7 Plato
        "The World is my country, all mankind are my brethren, and to do good is my religion. - Thomas Paine",                                           // 2/8 Thomas Paine
        "When we are no longer able to change a situation — we are challenged to change ourselves. - Viktor E. Frankl",                                  // 2/9 Viktor E. Frankl
        "Problems are not stop signs, they are guidelines. - Robert H. Schuller",                                                                        // 2/10 Robert H. Schuller
        "What we achieve inwardly will change outer reality. - Plutarch",                                                                                // 2/11 Plutarch
        "Spread love everywhere you go. Let no one ever come to you without leaving happier. - Mother Teresa",                                           // 2/12 Mother Teresa
        "We love life, not because we are used to living but because we are used to loving. - Friedrich Nietzsche",                                      // 2/13 Friedrich Nietzsche
        "You know you're in love when you can't fall asleep because the reality is finally better than you dreams. - Dr. Seuss",                         // 2/14 Dr. Seuss
        "All our dreams can come true, if we have the courage to pursue them. - Walt Disney",                                                            //2/15 Walt Disney
        "We know what we are but know not what we may be. - William Shakespeare",                                                                        // 2/16 William Shakespeare
        "It's not what you look at that matters, it's what you see. - Henry David Thoreau",                                                              // 2/17 Henry David Thoreau
        "A single rose can be my garden... a single friend, my world. - Leo Buscaglia",                                                                  // 2/18 Leo Buscaglia
        "Friends show their love in times of trouble, not in happiness. - Euripides",                                                                    // 2/19 Euripides
        "Life is not a problem to be solved, but a reality to be experienced. - Soren Kierkegaard",                                                      // 2/20 Soren Kierkegaard
        "The only true wisdom is in knowing you know nothing. - Socrates",                                                                               // 2/21 Socrates
        "A kiss is a lovely trick designed by nature to stop speech when words become superfluous. - Ingrid Bergman",                                    // 2/22 Ingrid Bergman
        "For it was not into my ear you whispered, but into my heart. It was not my lips you kissed by my soul. - Judy Garland",                         // 2/23 Judy Garland
        "If you live to be a hundred, I want to live to be a hundred minus one day so I never have to live without you. - A.A. Milne",                   // 2/24 A.A. Milne
        "As we express our gratitude, we must never forget that the highest appreciation is not to utter words, but to live by them. - John F. Kennedy", // 2/25 John F. Kennedy
        "Life's most persistent and urgent question is, 'What are you doing for others?' - Martin Luther King, Jr.",                                     //2/26 Martin Luther King, Jr.
        "Happiness resides not in possessions, and not in gold, happiness dwells in the soul. - Democritus",                                             // 2/27 Democritus
        "Believe you can and you're halfway there. - Theodore Roosevelt",                                                                                // 2/28 Theodore Roosevelt
        "The pessimist complains about the wind; the optimist expects it to change, the realist adjusts the sails. - William Arthur Ward"                // 2/29 William Arthur Ward
    };

    char *march_quotes[] = {
        "The future belongs to those who believe in the beauty of their dreams. - Eleanor Roosevelt",                                              // 3/1 Eleanor Roosevelt
        "Today you are you! That is truer than true! There is no one alive who is you-er than you! - Dr. Seuss",                                   // 3/2 Dr. Seuss
        "Education is the most powerful weapon which you can use to change the world - Nelson Mandela",                                            // 3/3 Nelson Mandela
        "Change your thoughts and you change your world. - Norman Vincent Peale",                                                                  // 3/4 Norman Vincent Peale
        "In three words I can sum up everything I've learned about life: it goes on. - Robert Frost",                                              // 3/5 Robert Frost
        "Love isn't something you find. Love is something that finds you. - Loretta Young",                                                        // 3/6 Loretta Young
        "Blessed are the hearts that can bend; they shall never be broken. - Albert Camus",                                                        // 3/7 Albert Camus
        "Do all things with love. - Og Mandino",                                                                                                   // 3/8 Og Mandino
        "I will not follow where the path may lead, but I will go where there is no path, and I will leave a trail. - Muriel Strode",              // 3/9 Muriel Strode
        "Where there is love there is life. - Mahatma Gandhi",                                                                                     // 3/10 Mahatma Gandhi
        "The only thing necessary for the triumph of evil is for good men to do nothing. - Edmund Burke",                                          // 3/11 Edmund Burke
        "Life isn't a fairytale. If you lose your shoe at midnight, you're drunk.",                                                                // 3/12 anonymous
        "Do not dwell in the past, do not dream of the future, concentrate the mind on the present moment. - Buddha",                              // 3/13 Buddha
        "Don't judge each day by the harvest you reap, but by the seeds that you plant. - Robert Louis Stevenson",                                 // 3/14 Robert Louis Stevenson
        "Nothing is impossible, the word itself says 'I'm possible'! - Audrey Hepburn",                                                            // 3/15 Audrey Hepburn
        "Find a place inside where there's joy, and the joy will burn out the pain. - Joseph Campbell",                                            // 3/16 Joseph Campbell
        "Try to be a rainbow in someone's cloud. - Maya Angelou",                                                                                  // 3/17 Maya Angelou
        "It is during our darkest moments that we must focus to see the light. - Aristotle",                                                       // 3/18 Aristotle
        "Keep love in your heart. A life without it is like a sunless garden when the flowers are dead. - Oscar Wilde",                            // 3/19 Oscar Wilde
        "The best and most beautiful things in the world cannot be seen or even touched — they must be felt with the heart. - Helen Keller",       // 3/20 Helen Keller
        "The only journey is the one within. - Maria Rilke",                                                                                       // 3/21 Maria Rilke
        "Good judgment comes from experience, and a lot of that comes from bad judgment. - Will Rogers",                                           // 3/22 Will Rogers
        "No act of kindness, no matter how small, is ever wasted. - Aesop",                                                                        // 3/23 Aesop
        "Love cures people both the ones who give it and the ones who receive it. - Karl A. Menninger",                                            // 3/24 Karl A. Menninger
        "Work like you don't need the money. Love like you've never been hurt. Dance like nobody's watching. - Satchel Paige",                     // 3/25 Satchel Paige
        "It is far better to be alone, than to be in bad company. - George Washington",                                                            // 3/26 George Washington
        "Be yourself; everyone else is already taken. - Oscar Wilde",                                                                              // 3/27 Oscar Wilde
        "No one can make you feel inferior without your consent. - Eleanor Roosevelt",                                                             // 3/28 Eleanor Roosevelt
        "Live as if you were to die tomorrow. Learn as if you were to live forever. - Mahatma Gandhi",                                             // 3/29 Mahatma Gandhi
        "Darkness cannot drive out darkness: only light can do that. Hate cannot drive out hate: only love can do that. - Martin Luther King Jr.", // 3/30 Martin Luther King Jr.
        "Without music, life would be a mistake. - Friedrich Nietzche"                                                                             // 3/31 Friedrich Nietzche
    };

    char *april_quotes[] = {
        "We accept the love we think we deserve. - Stephen Chbosky",                                                                                                                                                              // 4/1 Stephen Chbosky
        "Imperfection is beauty, madness is genius and it's better to be absolutely ridiculous than absolutely boring. - Marilyn Monroe",                                                                                         // 4/2 Marilyn Monroe
        "There are only two ways to live your life. One is as though nothing is a miracle. The other is as though everything is a miracle. - Albert Einstein",                                                                    // 4/3 Albert Einstein
        "We are all in the gutter, but some of us are looking at the stars. - Oscar Wilde",                                                                                                                                       // 4/4 Oscar Wilde
        "Fairy tales are more than true: not because they tell us that dragons exist, but because they tell us that dragons can be beaten. - Neil Gaiman",                                                                        // 4/5 Neil Gaiman
        "Yesterday is history, tomorrow is a mystery, today is a gift of God, which is why we call it the present. - Bill Keane",                                                                                                 // 4/6 Bill Keane
        "The opposite of love is not hate, it's indifference. - Elie Wiesel",                                                                                                                                                     // 4/7 Elie Wiesel
        "Knowledge is limited. Imagination encircles the world. - Albert Einstein",                                                                                                                                               // 4/8 Albert Einstein
        "You have brains in your head. You have feet in your shoes. You can steer yourself any direction you choose. You're on your own. And you know what you know. And YOU are the one who'll decide where to go. - Dr. Seuss", // 4/9 Dr. Seuss
        "It is never too late to be what you might have been. - George Eliot",                                                                                                                                                    // 4/10 George Eliot
        "There is no greater agony than bearing an untold story inside you. - Maya Angelou",                                                                                                                                      // 4/11 Maya Angelou
        "Everything you can imagine is real. - Pablo Picasso",                                                                                                                                                                    // 4/12 Pablo Picasso
        "You can never get a cup of tea large enough or a book long enough to suit me. -  C.S. Lewis",                                                                                                                            // 4/13 C.S. Lewis
        "To the well-organized mind, death is but the next great adventure. - J.K. Rowling",                                                                                                                                      // 4/14 J.K. Rowling
        "Life isn't about finding yourself. Life is about creating yourself. - George Bernard Shaw",                                                                                                                              // 4/15 George Bernard Shaw
        "Do what you can, with what you have, where you are. - Theodore Roosevelt",                                                                                                                                               // 4/16 Theodore Roosevelt
        "When one door of happiness closes, another opens; but often we look so long at the closed door that we do not see the one which has been opened for us. - Helen Keller",                                                 // 4/17 Helen Keller
        "Success is not final, failure is not fatal: it is the courage to continue that counts. - Winston Churchill",                                                                                                             // 4/18 Winston Churchill
        "You may say I'm a dreamer, but I'm not the only one. I hope someday you'll join us. And the world will live as one. - John Lennon",                                                                                      // 4/19 John Lennon
        "It's no use going back to yesterday, because I was a different person then. - Lewis Carroll",                                                                                                                            // 4/20 Lewis Carroll
        "A person's a person, no matter how small. - Dr. Seuss",                                                                                                                                                                  // 4/21 Dr. Seuss
        "Well-behaved women seldom make history. - Laurel Thatcher Ulrich",                                                                                                                                                       // 4/22 Laurel Thatcher Ulrich
        "So we beat on, boats against the current, borne back ceaselessly into the past. - F. Scott Fitzgerald",                                                                                                                  // 4/23 F. Scott Fitzgerald
        "I can't give you a sure-fire formula for success, but I can give you a formula for failure: try to please everybody all the time. - Herbert Bayard Swope",                                                               // 4/24 Herbert Bayard Swope
        "Do what you feel in your heart to be right — for you'll be criticized anyway. - Eleanor Roosevelt",                                                                                                                      // 4/25 Eleanor Roosevelt
        "Peace begins with a smile. - Mother Teresa",                                                                                                                                                                             // 4/26 Mother Teresa
        "If at first you don't succeed, call it version 1.0",                                                                                                                                                                     //4/27 Anonymous
        "What lies behind us and what lies before us are tiny matters compared to what lies within us. - Ralph Walso Emerson",                                                                                                    // 4/28 Ralph Walso Emerson
        "Software is like cathedrals. First we build them, then we pray.",                                                                                                                                                        // 4/29 Anonymous
        "Two wrongs don't make a right, but they make a good excuse. - Thomas Szasz"                                                                                                                                              // 4/30 Thomas Szasz
    };

    char *may_quotes[] = {
        "When you don't create things, you become defined by your tastes rather than ability. Your tastes only narrow & exclude people. So create.", // 5/1 Why The Lucky Stiff
        "Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live.",                        // 5/2 John Woods
        "Any fool can write code that a computer can understand. Good programmers write code that humans can understand.",                           // 5/3 Martin Fowler
        "I'm not a great programmer; I'm just a good programmer with great habits.",                                                                 // 5/4 Kent Beck
        "Truth can only be found in one place: the code.",                                                                                           // 5/5 Robert C. Martin
        "Give a man a program, frustrate him for a day. Teach a man to program, frustrate him for a lifetime.",                                      // 5/6 Muhammad Waseem
        "A language that doesn't affect the way you think about programming is not worth knowing.",                                                  // 5/7 Alan J Perlis
        "C:\\ \n  |_ Operating Systems\n    |_ Bad Grades\n      |_ **Error: File not found**",                                                      // 5/8
        // "The most important property of a program is whether it accomplishes the intention of its user.", // 5/8 C.A.R Hoare
        "Progress is possible only if we train ourselves to think about programs without thinking of them as pieces of executable code.", // 5/9 Edsger W. Dijstra
        "Delivering good software today is often better than perfect software tomorrow, so finish things and ship.",                      // 5/10 David Thomas
        "If you can write hello world you can change the world",                                                                          // 5/11 Raghu Venkatesh
        "Happiness should be a function without any parameters.",                                                                         // 5/12 Pranshu Midha
        "Most improved things can be improved.",                                                                                          // 5/13 Mokokoma Mokhonoana
        "Simple things should be simple, complex things should be possible.",                                                             // 5/14 Alan Kay
        "Programming isn't about what you know; it's about what you can figure out.",                                                     // 5/15 Chris Pine
        "Think twice, code once.",                                                                                                        // 5/16 Waseem Latif
        "Software testing is a sport like hunting, it's bughunting.",                                                                     // 5/17 Amit Kalantri
        "Programming is breaking of one big impossible task into several very small possible tasks.",                                     // 5/18 Jazzwant
        "Programmers are not mathematicians, no matter how much we wish and wish for it.",                                                // 5/19 Richard P. Gabriel
        "Think like a fundamentalist, code like a hacker.",                                                                               // 5/20 Erik Meijer
        "Redundant comments are just places to collect lies and misinformation.",                                                         // 5/21 Robert C. Martin
        "Life doesn't have a ctrl-z. Type wisely.",                                                                                       // 5/22 Imatiaz lqbal
        "Sometimes it pays to stay in bed on Monday, rather than spending the rest of the week debugging Monday's code.",                 // 5/23 Dan Soloman
        "Experience is the name everyone gives to their mistakes.",                                                                       // 5/24 Oscar Wilde
        "Java is to JavaScript what car is to Carpet.",                                                                                   // 5/25 - Chris Heilmann
        "Perfection is achieved not when there is nothing more to add, but rather when there is nothing more to take away",               // 5/26 Antoine de Saint-Exupery
        "Code is like humor. When you have to explain it, it's bad.",                                                                     // 5/27 Cory House
        "Optimism is an occupational hazard of programming: feedback is the treatment.",                                                  // 5/28 Kent Beck
        "Before software can be reusable it first has to be usable.",                                                                     // 5/29 Ralph Johnson
        "One of my most productive days was throwing away 1000 lines of code.",                                                           // 5/30 Ken Thompson
        "Deleted code is debugged code."                                                                                                  // 5/31 Jeff Sickel
    };

    char *june_quotes[] = {
        "Everything good, everything magical happens between the months of June and August.",                                     //6/1 Jenny Han
        "Maybe consider blue-light blocking glasses.",                                                                            //6/2
        "The summer night is like a perfection of thought.",                                                                      //6/3 Wallace Stevens
        "The best thing about a boolean is even if you are wrong, you are only off by a bit.",                                    //6/4 Anonymous
        "It's not a bug – it's an undocumented feature.",                                                                         //6/5 Anonymous
        "One man's crappy software is another man's full-time job.",                                                              //6/6 Jessica Gaston
        "Deleted code is debugged code.",                                                                                         //6/7 Jeff Sickel
        "If debugging is the process of removing software bugs, then programming must be the process of putting them in.",        //6/8 Edsger Dijkstra
        "Software undergoes beta testing shortly before it's released. Beta is Latin for still does not work.",                   //6/9 Anonymous "There are only two kinds of programming languages: those people always bitch about and those nobody uses.", // 6/10 Bjarne Stroustrup
        "Don't worry if it doesn't work right. If everything did, you'd be out of a job.",                                        //6/11  Mosher's Law of Software Engineering
        "Software is like cathedrals. First we build them, then we pray.",                                                        //6/12 Anonymous DAY OF?
        "C makes it easy to shoot yourself in the foot; C++ makes it harder, but when you do it blows your whole leg off.",       //6/13  Bjarne Stroustrup
        "Blame doesn't fix bugs",                                                                                                 //6/14 Anonymous
        "There are three levels of design: It can be foolproof, Sometimes it can be idiot proof, It can never be asshole proof.", //6/15 Anonymous
        "Software Developer: An organism that turns caffeine into software",                                                      //6/16 Anonymous
        "A user interface is like a joke. If you have to explain it, it's not that good",                                         //6/17 Anonymous
        "Measuring programming progress by lines of code is like measuring aircraft building progress by weight. - Bill Gates",   //6/18 Bill Gates
        "My code DOESN'T work, I have no idea why. My code WORKS, I have no idea why.",                                           //6/19 Anonymous
        "If at first you don't succeed; call it version 1.0",                                                                     //6/20 Anonymous
        "If Internet Explorer is brave enough to ask to be your default browser, YOU are brave enough to ask your crush out.",    //6/21 Anonymous
        "A misplaced decimal point will always end up where it will do the greatest damage.",                                     //6/22 Anonymous
        "A computer program does what you tell it to do, not what you want it to do.",                                            //6/23 Anonymous
        "First, solve the problem. Then, write the code.",                                                                        //6/24 John Johnson""
        "Experience is the name everyone gives to their mistakes. - Oscar Wilde",                                                 //6/25 Oscar Wilde
        "Computers make very fast, very accurate mistakes.",                                                                      //6/26 Anonymous
        "Life would be so much easier if we only had the source code.",                                                           //6/27 Anonymous
        "Only half of programming is coding. The other 90% is debugging.",                                                        //6/28 Anonymous
        "Profanity is the one language all programmers know best.",                                                               //6/29 Anonymous
        "There's no test like production.",                                                                                       //6/30 Anonymous
        "Weeks of coding can save you hours of planning."                                                                         //6/31 Anonymous
    };

    char *july_quotes[] = {
        "The central enemy of reliability is complexity.",                                                                                     // 7/1 Geer et al
        "Simplicity is prerequisite for reliability.",                                                                                         // 7/2 Edsger W. Djikstra
        "There are 10 types of people in this world, those who understand binary and those who don't.",                                        // 7/3
        "A code is like love, it has created with clear intentions at the beginning, but it can get complicated.",                             // 7/4 Gerry Greek
        "Don't worry if it doesn't work right. If everything did, you'd be out of a job.",                                                     // 7/5
        "Linux is only free if your time has no value.",                                                                                       // 7/6
        "Premature optimization is the root of all evil.",                                                                                     // 7/7
        "No one in the brief history of computing has ever written a piece of perfect software. It's unlikely that you'll be the first.",      // 7/8
        "What one programmer can do in one month, two programmers can do in two months.",                                                      // 7/9 Fred Brooks
        "Software being Done is like lawn being 'Mowed",                                                                                       // 7/10 Jim Benson
        "There's no test like production.",                                                                                                    // 7/11
        "A user interface should be so simple that a beginner in an emergency can understand it within ten seconds.",                          // 7/12 Ted Nelson
        "One man's constant is another man's variable.",                                                                                       // 7/13 Alan J. Perlis
        "One of the best programming skills you can have is knowing when to walk away for awhile.",                                            // 7/14 Oscar Godson
        "The best thing about a boolean is even if you are wrong, you are only off by a bit.",                                                 // 7/15
        "The function of good software is to make the complex appear to be simple.",                                                           // 7/16 Grady Booch
        "Measuring programming progress by lines of code is like measuring aircraft building progress by weight. - Bill Gates",                // 7/17 Bill Gates
        "Good programmers use their brains, but good guidelines save us having to think out every case.",                                      // 7/18 Francis Glassborow
        "You can't have great software without a great team, and most software teams behave like dysfunctional families.",                     // 7/19 Jim McCarthy
        "If debugging is the process of removing bugs, then programming must be the process of putting them in.",                              // 7/20 Edsger W. Dijkstra
        "Java: write once, run away!",                                                                                                         // 7/21
        "When debugging, novices insert corrective code; experts remove defective code",                                                       // 7/22
        "Don't include a single line in your code which you could not explain to your grandmother in a matter of two minutes.",                // 7/23
        "Good design adds value faster than it adds cost.",                                                                                    // 7/24
        "A complex system that works is invariably found to have evolved from a simple system that worked.",                                   //7/25
        "Programs must be written for people to read, and only incidentally for machines to execute.",                                         // 7/26
        "hard enough to find an error in your code when you're looking for it; it's even harder when you've assumed your code is error-free.", // 7/27
        "Everyday life is like programming, I guess. If you love something you can put beauty into it.",                                       // 7/28
        "I'm not a great programmer; I'm just a good programmer with great habits.",                                                           // 7/29
        "It's not at all important to get it right the first time. It's vitally important to get it right the last time.",                     // 7/30
        "Low-level programming is good for the programmer's soul."                                                                             //7/31
    };

    char *august_quotes[] = {
        "When you have eliminated all which is impossible, then whatever remains, however improbable, must be the truth.",                                                                            // 8/1 Arthur Conan Doyle
        "If you remember me, then I don't care if everyone else forgets.",                                                                                                                            // 8/2 Haruki Murakami
        "Prayer is not asking. It is a longing of the soul. It is daily admission of one's weakness. It is better in prayer to have a heart without words than words without a heart.",               //8/3 Mahatma Gandhi
        "Attitude is a choice. Happiness is a choice. Optimism is a choice. Kindness is a choice. Giving is a choice. Respect is a choice. Whatever choice you make makes you. Choose wisely.",       // 8/4 Roy T. Bennett
        "It isn't what you have or who you are or where you are or what you are doing that makes you happy or unhappy. It is what you think about it.",                                               // 8/5 Dale Carnegie
        "And, in the end, the love you take is equal to the love you make.",                                                                                                                          // 8/6 Paul McCartney
        "The future belongs to those who believe in the beauty of their dreams."                                                                                                                      // 8/7 Eleanor Roosevelt
        "I like living. I have sometimes been  wildly, despairingly, acutely miserable, racked with sorrow; but through it all I still know quite certainly that just to be alive is a grand thing.", // 8/8 Agatha Christie
        "I do not fear death. I had been dead for billions and billions of years before I was born, and had not suffered the slightest inconvenience from it.",                                       // 8/9 Mark Twain
        "But I know, somehow, that only when it is dark enough can you see the stars.",                                                                                                               // 8/10 Martin Luther King, Jr.
        "None but ourselves can free our minds.",                                                                                                                                                     // 8/11 Bob Marley
        "Sometimes our light goes out, but is blown again into instant flame by an encounter with another human being.",                                                                              // 8/12 Albert Schweitzer
        "People say nothing is impossible, but I do nothing every day.",                                                                                                                              // 8/13 A.A. Milne
        "It's kind of fun to do the impossible.",                                                                                                                                                     // 8/14 Walt Disney
        "Pain is temporary. Quitting lasts forever."                                                                                                                                                  // 8/15 Lance Armstrong
        "It's only after you've stepped outside your comfort zone that you begin to change, grow, and transform.",                                                                                    // 8/16 Roy T. Bennett
        "All the darkness in the world cannot extinguish the light of a single candle.",                                                                                                              // 8/17 St. Francis of Assisi
        "You never fail until you stop trying.",                                                                                                                                                      // 8/18 Albert Einstein
        "Stories never really end...even if the books like to pretend they do. Stories always go on. They don't end on the last page, any more than they begin on the first page.",                   // 8/19 Cornelia Funke
        "Why didn't I learn to treat everything like it was the last time. My greatest regret was how much I believed in the future.",                                                                // 8/20 Jonathan Safran Foer
        "Dance, when you're broken open. Dance, if you've torn the bandage off. Dance in the middle of the fighting. Dance in your blood. Dance when you're perfectly free.",                         // 8/21 Rumi
        "Any fool can be happy. It takes a man with real heart to make beauty out of the stuff that makes us weep.",                                                                                  // 8/22 Clive Barker
        "It is the time you have wasted for your rose that makes your rose so important.",                                                                                                            // 8/23 Antoine de Saint-Exupery
        "You were born with wings, why prefer to crawl through life?",                                                                                                                                // 8/24 Rumi
        "Live in the present, remember the past, and fear not the future, for it doesn't exist and never shall. There is only now.",                                                                  // 8/25 Christopher Paolini
        "We are just an advanced breed of monkeys on a minor planet of a very average star. But we can understand the Universe. That makes us something very special.",                               // 8/26 Stephen Hawking
        "Life is a shipwreck, but we mnust not forget to sing in the lifeboats.",                                                                                                                     // 8/27 Voltaire
        "A ship is safe in harbor, but that's not what ships are for.",                                                                                                                               // 8/28 John A. Shedd
        "The most common way people give up their power is by thinking they don't have any.",                                                                                                         // 8/29 Alice Walker
        "May the forces of evil become confused on the way to your house.",                                                                                                                           // 8/30 George Carlin
        "The worst part of success is trying to find someone who is happy for you."                                                                                                                   // 8/31 Bette Midler
    };

    char *september_quotes[] = {
        "If you like nerds, raise your hand. If you don't, raise your standards.",                                                                                                                                        // 9/1 Violet Haberdasher
        "Charm is the ability to insult people without offending them; nerdiness the reverse.",                                                                                                                           // 9/2 Nassim Nicholas Taleb
        "So you're a little weird? Work it! A little different? OWN it! Better to be a nerd than one of the herd!",                                                                                                       // 9/3 Mandy Hale
        "I will take a serious approach to a subject usually treated lightly, which is a nerdy thing to do.",                                                                                                             // 9/4 Benjamin Nugent
        "Dear cool people: They didn't name a candy after you, did they? Sincerely, Nerds.",                                                                                                                              // 9/5
        "Nerd is not just a 4 letter word. It's a future 6 digit salary.",                                                                                                                                                // 9/6
        "In a nerd wedding, they don't say 'I do.' They say, 'I accept the terms and conditions.'",                                                                                                                       // 9/7
        "Think like a proton and stay *positive*.",                                                                                                                                                                       // 9/8
        "There is no place like 127.0.0.1",                                                                                                                                                                               // 9/9
        "Guys are like Internet Domain names; the ones I like are already taken.",                                                                                                                                        // 9/10
        "Programming today is a race between software engineers striving to build bigger and better idiot-proof programs, and the universe trying to produce bigger and better idiots. So far, the universe is winning.", // 9/11
        "Computers are incredibly fast, accurate, and stupid; humans are incredibly slow, inaccurate and brilliant; together they are powerful beyond imagination. - Albert Einstein"                                     //9/12
        "There are 10 types of people in the world: those who understand binary and those who don't.",                                                                                                                    // 9/13
        "1f u c4n r34d th1s u r34lly n33d t0 g37 l41d",                                                                                                                                                                   // 9/14
        "I'm not anti-social; I'm just not user friendly.",                                                                                                                                                               // 9/15
        "I would love to change the world, but they won't give me the source code.",                                                                                                                                      // 9/16
        "My software never has bugs. It just develops random features.",                                                                                                                                                  // 9/17
        "The glass is neither half-full nor half-empty: it's twice as big as it needs to be.",                                                                                                                            // 9/18
        "Passwords are like underwear. You shouldn't leave them out where people can see them. You should change them regularly. And you shouldn't loan them out to strangers",                                           // 9/19
        "Enter any 11 digit prime number to continue.",                                                                                                                                                                   //9/20
        "A life? cool! Where can I download one of those?",                                                                                                                                                               // 9/21
        "I spent a minute looking at my own code by accident. I was thinking 'what the hell is this guy doing?'",                                                                                                         // 9/22
        "Concept: On the keyboard of life, always keep one finger on the escape button.",                                                                                                                                 // 9/23
        "A computer lets you make more mistakes faster than any invention in human history – with the possible exceptions of handguns and tequila.",                                                                      // 9/24
        "People say that if you play Microsoft CDs backwards, you hear satanic things, but thats nothing, because if you play them forwards, they install Windows.",                                                      // 9/25
        "In a world without fences and walls, who needs Gates and Windows?",                                                                                                                                              // 9/26
        "Who needs friends? My PC is user friendly.",                                                                                                                                                                     // 9/27
        "Just move to the Internet, it's great here. We get to live inside where the weather is always awesome.",                                                                                                         // 9/28
        "Like the famous mad philosopher said, when you stare into the void, the void stares also; but if you cast into the void, you get a type conversion error.",                                                      // 9/29
        "You know what seems odd to me? Numbers that aren't divisible by two."                                                                                                                                            // 9/30
    };

    char *october_quotes[] = {
        "Who is General Failure? And why is he reading my disk?",                                                                                          //10/1 Anonymous
        "Judge a person by their questions rather than by their answers.",                                                                                 //10/2 Voltaire
        "Just don't create a file called -rf.",                                                                                                            //10/3 Larry Wall
        "Let's call it an accidental feature",                                                                                                             //10/4 Larry Wall
        "Perl - The only language that looks the same before and after RSA encryption.",                                                                   //10/5 Keith Bostic
        "The problem with troubleshooting is that trouble shoots back.",                                                                                   //10/6 Anonymous
        "The three great virtues of a programmer: laziness, impatience, and hubris.",                                                                      //10/7 Larry Wall
        "Sometimes it pays to stay in bed on Monday, rather than spending the rest of the week debugging Monday's code.",                                  //10/8 Don Salomon
        "It´s better to wait for a productive programmer to become available than it is to wait for the first available programmer to become productive.", //10/9 Steve McConnell
        "Inside every large program, there is a program trying to get out.",                                                                               //10/10 C.A.R Hoare
        "Why do we never have time to do it right, but always have time to do it over?",                                                                   //10/11 Anonymous
        "The best way to get a project done faster is to start sooner",                                                                                    //10/12 Jim Highsmith
        "If there is no struggle, there is no progress.",                                                                                                  //10/13 Frederick Douglass
        "A person who never made a mistake never tried anything new.",                                                                                     //10/14 Albert Einstein
        "Logic will get you from A to B. Imagination will take you everywhere.",                                                                           //10/15 Albert Einstein
        "Never let your schooling interfere with your education.",                                                                                         //10/16 Mark Twain
        "The secret of getting ahead is getting started.",                                                                                                 //10/17 Mark Twain
        "Before you marry a person you should first make them use a computer with slow Internet to see who they really are.",                              //10/18 Will Ferrell
        "They did not know it was impossible, so they did it!",                                                                                            //10/19 Mark Twain
        "Good is the enemy of great, but great is the enemy of shipped.",                                                                                  //10/20 Jeffrey Zeldman
        "If the programmers like each other, they play a game called 'pair programming'. And if not then the game is called 'peer review'.",               //10/21 Anna Nachesa
        "The best engineers I know are artists at heart. The best designers I know are secretly technicians as well.",                                     //10/22 Andrei Herasimchuk
        "No one hates software more than software developers.",                                                                                            //10/23 Jeff Atwood
        "The proper use of comments is to compensate for our failure to express ourself in code.",                                                         //10/24 Robert C. Martin
        "Design is choosing how you will fail.",                                                                                                           //10/25 Ron Fein
        "Focus is saying no to 1000 good ideas.",                                                                                                          //10/26 Steve Jobs
        "That's what's cool about working with computers.  They don't argue, they remember everything, and they don't drink all your beer.",               //10/27 Paul Leary
        "The question of whether computers can think is like the question of whether submarines can swim.",                                                //10/28 Edsger W. Dijkstra
        "Hardware: The parts of a computer system that can be kicked.",                                                                                    //10/29 Jeff Pesis
        "I've finally learned what 'upward compatible' means.  It means we get to keep all our old mistakes.",                                             //10/30 Dennie van Tassel
        "Every operating system out there is about equal… We all suck."                                                                                    //10/31 Brian Valentine Microsoft Senior VP
    };

    char *november_quotes[] = {
        "If you put root beer in a square cup, do you get beer?",                                                                                                                                                                                                                                                                  // 11/1
        "Parallel lines have so much in common... it's a shame that they'll never meet.",                                                                                                                                                                                                                                          // 11/2
        "Be nice to nerds. You may end up working for them.",                                                                                                                                                                                                                                                                      // 11/3
        "Programmers hate roman numerals but I can't zero in on why.",                                                                                                                                                                                                                                                             // 11/4
        "Math. The only place where people can buy 64 watermelons and no one wonders why.",                                                                                                                                                                                                                                        // 11/5
        "4 out of 3 people struggle with math.",                                                                                                                                                                                                                                                                                   // 11/6
        "Math is fun, it teaches you life and death information, like when you're cold, you should go to a corner since it's 90 degrees there.",                                                                                                                                                                                   /// 11/7
        "I stopped understanding math when the alphabet decided to get involved.",                                                                                                                                                                                                                                                 // 11/8
        "If I had just one hour left to live, I'd spend it in OS class... it never ends. JUST KIDDING!",                                                                                                                                                                                                                           // 11/9
        "In math class we learned more about algebra, such as X + 10 = Y should I care?",                                                                                                                                                                                                                                          // 11/10
        "It's easy to identify people who can't count to ten. They're in front of you in the supermarket express lane.",                                                                                                                                                                                                           // 11/11
        "I changed my password everywhere to 'incorrect.' that way when I forget it, it always reminds me, 'your password is incorrect.'",                                                                                                                                                                                         // 11/12
        "The only relationship I have is with my Wi-Fi. We have a connection.",                                                                                                                                                                                                                                                    // 11/13
        "A computer once beat me at chess, but it was no match for me at kickboxing.",                                                                                                                                                                                                                                             // 11/14
        "If you think patience is a virtue, try surfing the net without high speed internet.",                                                                                                                                                                                                                                     // 11/15
        "Life is too short to remove a USB safely.",                                                                                                                                                                                                                                                                               // 11/16
        "The only sure way to make a computer go faster is to throw it out the window.",                                                                                                                                                                                                                                           // 11/17
        "Programmers are tools for converting caffeine into code.",                                                                                                                                                                                                                                                                // 11/18
        "A common mistake people make when trying to design something completely foolproof is understanding the ingenuity of complete fools.",                                                                                                                                                                                     // 11/19
        "Programs are like women. No matter how much you get mad because of errors, you're always the one who is wrong.",                                                                                                                                                                                                          // 11/20
        "Life before the computer: \n - memory was something that you lost with age \n - an application was for employment \n - a program was a TV show \n - a cursor used profanity \n - a keyboard was a piano \n - a virus was the flu \n - a hard drive was a long trip on the road \n - a mouse pad was where a mouse lived", // 11/21
        "You don't know something? Google it. You don't know someone? Facebook it. You can't find something? Scream, 'Mom, I need help!'",                                                                                                                                                                                         // 11/22
        "Once upon a time I had a life, now I have an Internet connection.",                                                                                                                                                                                                                                                       // 11/23
        "Curiously, once technology gets boring, the social effects get interesting.",                                                                                                                                                                                                                                             // 11/24
        "Almost everything will work again if you unplug it for a few minutes, including you.",                                                                                                                                                                                                                                    // 11/25
        "I changed my password everywhere to 'incorrect.' That way when I forget it, it always reminds me, 'Your password is incorrect.'",                                                                                                                                                                                         // 11/26
        "A computer once beat me at chess, but it was no match for me at kick boxing.",                                                                                                                                                                                                                                            // 11/27
        "Never let a computer know you're in a hurry.",                                                                                                                                                                                                                                                                            // 11/28
        "Computer Science is no more about computers than astronomy is about telescopes.",                                                                                                                                                                                                                                         // 11/29
        "Do files get embarrassed when they're unzipped?"                                                                                                                                                                                                                                                                          // 11/30
    };

    char *december_quotes[] = {
        "The most amazing achievement of the computer software industry is its continuing cancellation of the steady and staggering gains made by the computer hardware industry.",                                                                              //12/1 Henry Petroski
        "No matter how slick the demo is in rehearsal, when you do it in front of a live audience, the probability of a flawless presentation is inversely proportional to the number of people watching, raised to the power of the amount of money involved.", //12/2 Mark Gibbs
        "There are two ways of constructing a software design.  One way is to make it so simple that there are obviously no deficiencies. And the other way is to make it so complicated that there are no obvious deficiencies.",                               //12/3 C.A.R. Hoare
        "The function of good software is to make the complex appear to be simple.",                                                                                                                                                                             //12/4 Grady Booch
        "That's the thing about people who think they hate computers.  What they really hate is lousy programmers.",                                                                                                                                             //12/5 Larry Niven
        "First learn computer science and all the theory.  Next develop a programming style.  Then forget all that and just hack.",                                                                                                                              //12/6 George Carrette
        "To iterate is human, to recurse divine.",                                                                                                                                                                                                               //12/7 L. Peter Deutsch
        "Should array indices start at 0 or 1?  My compromise of 0.5 was rejected without, I thought, proper consideration.",                                                                                                                                    //12/8 Stan Kelly-Bootle
        "There is no programming language–no matter how structured–that will prevent programmers from making bad programs.",                                                                                                                                     //12/9 Larry Flon
        "Computer language design is just like a stroll in the park.  Jurassic Park, that is.",                                                                                                                                                                  //12/10 Larry Wall
        "Fifty years of programming language research, and we end up with C++?",                                                                                                                                                                                 //12/11 Richard A. O'Keefe
        "One of the main causes of the fall of the Roman Empire was that–lacking zero–they had no way to indicate successful termination of their C programs.",                                                                                                  //12/12 Robert Firth
        "Fine, Java MIGHT be a good example of what a programming language should be like.  But Java applications are good examples of what applications SHOULDN'T be like.",                                                                                    //12/13 pixadel
        "If Java had true garbage collection, most programs would delete themselves upon execution.",                                                                                                                                                            //12/14 Robert Sewell
        "The only people who have anything to fear from free software are those whose products are worth even less.",                                                                                                                                            //12/15 David Emery
        "Good code is its own best documentation.",                                                                                                                                                                                                              //12/16 Steve McConnell
        "Q: Why do Java programmers have to wear glasses? A: Because they don't C#",                                                                                                                                                                             //12/17 Anonymous
        "Cheers to a new year and another chance for us to get it right.",                                                                                                                                                                                       //12/18 Oprah
        "The first step towards getting somewhere is to decide you're not going to stay where you are.",                                                                                                                                                         //12/19 J.P Moran
        "Computers are like air conditioners. They work fine until you start opening windows.",                                                                                                                                                                  //12/20 Anonymous
        "Home is where you hang your @.",                                                                                                                                                                                                                        // 12/21
        "To have no errors. Would be life without meaning. No struggle, no joy",                                                                                                                                                                                 // 12/22
        "In a few minutes a computer can make a mistake so great that it would have taken many men many months to equal it.",                                                                                                                                    // 12/23
        "Mac users swear by their computers.  PC users swear at their computers.",                                                                                                                                                                               // 12/24
        "People think computers will keep them from making mistakes. They're wrong. With computers you make mistakes faster.",                                                                                                                                   // 12/25
        "while(!(succeed = try() ) );",                                                                                                                                                                                                                          //12/26
        "The most important property of a program is whether it accomplishes the intention of its user.",                                                                                                                                                        //12/27 C.A.R. Hoare
        "...if you aren't, at any given time, scandalized by code you wrote five or even three years ago, you're not learning anywhere near enough",                                                                                                             //12/28 Nick Black
        "No technology that's connected to the internet is unhackable.",                                                                                                                                                                                         //12/29 Abhijit Naskar
        "Success is not final, failure is not fatal: it is the courage to continue that counts. - Winston Churchhill",                                                                                                                                           // 12/20 Winston Churchhill
        "Happy new year!"                                                                                                                                                                                                                                        // 12/31
    };

    switch (month)
    {
    case 1:
        printk("Quote of the Day: \n %s \n", january_quotes[day - 1]);
        break;
    case 2:
        printk("Quote of the Day:  \n %s \n", february_quotes[day - 1]);
        break;
    case 3:
        printk("Quote of the Day: \n %s \n", march_quotes[day - 1]);
        break;
    case 4:
        printk("Quote of the Day: \n %s \n", april_quotes[day - 1]);
        break;
    case 5:
        printk("Quote of the Day: \n %s \n", may_quotes[day - 1]);
        break;
    case 6:
        printk("Quote of the Day: \n %s \n", june_quotes[day - 1]);
        break;
    case 7:
        printk("Quote of the Day: \n %s \n", july_quotes[day - 1]);
        break;
    case 8:
        printk("Quote of the Day: \n %s \n", august_quotes[day - 1]);
        break;
    case 9:
        printk("Quote of the Day: \n %s \n", september_quotes[day - 1]);
        break;
    case 10:
        printk("Quote of the Day: \n %s \n", october_quotes[day - 1]);
        break;
    case 11:
        printk("Quote of the Day: \n %s \n", november_quotes[day - 1]);
        break;
    case 12:
        printk("Quote of the Day: \n %s \n", december_quotes[day - 1]);
        break;
    }

    return 0;
}