\# Phantom Passenger – Game Design Document



\*\*Genre:\*\* Cute Horror / Deduction / Inspection  

\*\*Perspective:\*\* Fixed 3/4 camera, bus interior  

\*\*Platform:\*\* PC / Game Jam prototype  



\## Concept Overview

A ghostly presence boards a bus, disguised as a normal passenger. Players must identify the phantom before the final stop using observations, dialogue, ticket inspections, and items.  



\### Core Experience

\- Cute horror aesthetic  

\- UI-driven interactions: tickets, dialogue, items, observations  

\- Replayable with randomized passengers and clues  



\## Core Gameplay Loop

1\. \*\*Board Bus:\*\* Empty bus, passengers randomly board  

2\. \*\*Passenger Events:\*\* New passengers each stop (5 stops total)  

3\. \*\*UI Interactions:\*\* Ask questions, check tickets, offer items, observe  

4\. \*\*Clue Collection:\*\* Track true and false clues in a notebook  

5\. \*\*Deduction:\*\* Player selects phantom at final stop; correct/incorrect outcome  



\## Randomization \& Replayability

\- Phantom assigned randomly per run  

\- Passenger personalities, dialogue, and items randomized  

\- Tickets and clues partially randomized  

\- Minor visual/sound events for flavor  



\## Passenger Archetypes

| Archetype            | Traits                     | Possible Clues                 |

|---------------------|----------------------------|-------------------------------|

| Nervous One          | Fidgets, avoids eye contact| Dropped charm, suspicious behavior |

| Chatty Gossip        | Talks freely               | May mislead about other passengers |

| Suspicious Silent    | Rarely talks               | Observation required, ticket mismatch |

| Eccentric            | Weird gestures, cryptic    | Cryptic true clues             |

| Helper               | Offers items or hints      | Can react strategically with items |



\## Items \& Interactions

\- \*\*Candies/Charms:\*\* Reveal supernatural reactions if phantom is nearby  

\- \*\*Ticket:\*\* UI panel; mismatches reveal clues  

\- \*\*Notebook/Clue Book:\*\* Cross-reference observations and passenger behavior  



\## UI Design

\- Dialogue box with multiple-choice questions  

\- Ticket inspection panel  

\- Inventory for items to offer  

\- Notebook/Clue Book to track clues  

\- Hover/observe visual feedback: glows, footprints, ectoplasm  



\## Visual \& Material Design

\- Low-poly bus and passengers  

\- Cel-shaded materials  

\- Particle effects for ghostly cues  

\- Color-coded or subtle visual feedback for clues  



\## Technical Notes

\- Focus on UI systems first  

\- Keep bus interior static, minimal animation  

\- Randomization via simple arrays  

\- Stylized Unreal materials instead of complex textures  



\## MVP

\- Single bus route (5 stops)  

\- 5–7 passengers, 1 phantom  

\- 3–4 UI interactions per passenger  

\- Notebook/clue book to track clues  

\- Randomized traits, tickets, and clues  

\- One correct ending, one fail ending



