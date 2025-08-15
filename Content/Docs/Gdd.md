\# Phantom Passenger – Game Design Document



\*\*Genre:\*\* Cute Horror / Deduction / Inspection  

\*\*Perspective:\*\* Fixed 3/4 camera, bus interior  

\*\*Platform:\*\* PC



---



\## Concept Overview

A ghostly presence boards a bus, disguised as a normal passenger. Players must identify the phantom before the final stop by observing behavior, engaging in dialogue, inspecting tickets, and offering items.  



\### Core Experience

\- Cute horror aesthetic  

\- UI-driven interactions: tickets, dialogue, items, and observations  

\- Replayable with randomized passengers, clues, tickets, and items  



---



\## Gameplay Loop



\*\*1. Passenger Boarding\*\*  
\-Event: All passengers are spawned at the start of the game.

\- Event: Passengers board the bus at each stop (5 stops).  (Hard mode/ later?)

\- Player Action: Observe passengers’ behavior (hover effects, visual cues).  



\*\*2. Click → Interaction Menu\*\*  

\- Player clicks a passenger → context menu appears with options:  

&nbsp; 1. \*\*Chat / Ask Questions\*\* → opens dialogue panel  

&nbsp; 2. \*\*Inspect Ticket\*\* → opens ticket panel  

&nbsp; 3. \*\*Offer Item\*\* → opens inventory to give an item  

&nbsp; 4. \*\*Observe\*\* → passive hover cues or tooltip hints  



\*\*3. Dialogue / Questions\*\*  

\- Ask about ticket → triggers ticket inspection  

\- Ask about other passengers → true/misleading info  

\- Offer item → triggers supernatural reaction if phantom  



\*\*4. Ticket Inspection\*\*  

\- Open passenger ticket panel  

\- Compare ticket fields to the bus’s current route, date, time, and number  

\- Mismatches highlighted and logged in notebook  



\*\*5. Item Interactions (Truth vs Decoy Items)\*\*  

\- \*\*Truth Item:\*\* Only one per run; triggers strong supernatural reaction if used on phantom; logs major clue  

\- \*\*Decoy Items:\*\* Minor feedback, flavour reactions, or small clues; cannot identify the phantom directly  

\- Encourages strategic observation + deduction instead of item spamming  



\*\*6. Observation \& Notebook\*\*  

\- Hover/passively watch passengers  

\- Record observations in notebook; review all clues  



\*\*7. Deduction / Final Stop\*\*  

\- End of last stop → use notebook clues and item reactions to select the phantom  

\- Correct → success animation; Incorrect → hints for replay  



\*\*Loop Summary:\*\*  

Passenger Boarding → Click → Interaction Menu → Dialogue / Ticket / Item / Observe → Notebook Review → Next Stop → \[Repeat until final stop] → Deduction



\## Randomization \& Replayability

\- Phantom passenger assigned randomly each run  

\- Passenger archetypes, traits, dialogues, and items randomized  

\- Tickets and clues partially randomized  

\- Minor visual/sound events for flavor  

\- Randomized bus date/time and route/number per run to ensure ticket checks remain meaningful  

\- Truth item randomly assigned each run  



---



\## Passenger Archetypes

| Archetype            | Traits                     | Possible Clues                 |

|---------------------|----------------------------|-------------------------------|

| Nervous One          | Fidgets, avoids eye contact| Dropped charm, suspicious behavior |

| Chatty Gossip        | Talks freely               | May mislead about other passengers |

| Suspicious Silent    | Rarely talks               | Observation required, ticket mismatch |

| Eccentric            | Weird gestures, cryptic    | Cryptic true clues             |

| Helper               | Offers items or hints      | Can react strategically with items |



---



\## Items \& Interactions

\- \*\*Candies/Charms:\*\* Only one “truth item” per run can definitively react to phantom; others are decoys  

\- \*\*Ticket:\*\* UI panel; mismatches reveal clues  

\- \*\*Notebook/Clue Book:\*\* Cross-reference observations, ticket checks, and item reactions  

\- \*\*Item Strategy:\*\* Encourages deduction and observation over random item use  



---



\## Ticket System

\- Each passenger has a ticket with randomized fields:  

&nbsp; - Name  

&nbsp; - Destination Stop  

&nbsp; - Date (matches current run, randomized per game)  

&nbsp; - Time / Boarding Stop  

&nbsp; - Bus / Route Number (randomized per game)  

&nbsp; - Seat Number (optional)  

\- Mismatches highlighted (color-coded) and logged in notebook.  

\- Phantom more likely to have multiple mismatches; other passengers may have minor mismatches as misdirection.  



---



\## UI Design

1\. \*\*Observation Layer\*\*  

&nbsp;  - Hover highlights subtle behaviors  

&nbsp;  - Tooltips show brief hints  



2\. \*\*Passenger Interaction Menu\*\*  

&nbsp;  - Click passenger → radial or vertical menu  

&nbsp;  - Options: Chat, Inspect Ticket, Offer Item, Observe  

&nbsp;  - Greyed out if unavailable; hover shows tooltips  



3\. \*\*Dialogue Panel\*\*  

&nbsp;  - Context-sensitive options: Ask, Offer Item, Inspect Ticket  



4\. \*\*Ticket Panel\*\*  

&nbsp;  - Shows all ticket fields clearly  

&nbsp;  - Color-coded mismatches:  

&nbsp;    - Green → matches bus info  

&nbsp;    - Yellow → minor mismatch  

&nbsp;    - Red → definite mismatch  



5\. \*\*Inventory / Items\*\*  

&nbsp;  - Select or drag-and-drop items to passengers  

&nbsp;  - Only the truth item triggers major phantom reaction  

&nbsp;  - Decoy items provide minor feedback or flavor clues  



6\. \*\*Notebook / Clue Book\*\*  

&nbsp;  - Automatically logs clues from observation, ticket, and items  

&nbsp;  - Manual note-taking for player deductions  

&nbsp;  - Accessible at any time  



7\. \*\*End-of-Stop Summary (Optional)\*\*  

&nbsp;  - Pop-up highlighting new clues  

&nbsp;  - Encourages review before next stop  



---



\## Visual \& Material Design

\- Low-poly bus and passengers  

\- Cel-shaded materials  

\- Particle effects for ghostly cues  

\- Color-coded or subtle visual feedback for clues  



---



\## Technical Notes

\- Focus on UI systems first (interaction menu, dialogue, ticket, inventory, notebook)  

\- Keep bus interior static, minimal animation  

\- Randomization via simple arrays for passengers, tickets, items, and clues  

\- Stylized Unreal materials instead of complex textures  



---



\## MVP

\- Single bus route (5 stops)  

\- 5–7 passengers, 1 phantom  

\- Click-on-passenger interaction menu  

\- 3–4 UI interactions per passenger  

\- Notebook/clue book to track clues  

\- Randomized traits, tickets, and clues  

\- Randomized truth item per run  

\- One correct ending, one fail ending  

