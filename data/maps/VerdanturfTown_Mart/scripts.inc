VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_FLUFFY_TAIL
    .2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "Shhh. I'm just hanging out here\n"
	.string "for the cold A/C.\p"
	.string "My power went out this morning\n"
	.string "and it's fucking 95 out there.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "Time for my daily lotto tickets!\n"
	.string "I buy 10 scratchers every day.\p"
	.string "I hope you don't mind waiting\n"
	.string "behind me in line...$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "Hi! Do you want to buy some\n"
	.string "Girl Scout cookies from me?\p"
	.string "My mom is waiting outside here\n"
	.string "to try and guilt you into it.$"

